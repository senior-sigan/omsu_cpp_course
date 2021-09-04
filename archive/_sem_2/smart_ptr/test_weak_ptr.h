#pragma once

#include <cassert>

#include "weak_ptr.h"

struct Node;

struct Next {
  shared_ptr<Node> shared;
  weak_ptr<Node> weak;
  Next(const shared_ptr<Node>& shared) : shared(shared) {}
  Next(const weak_ptr<Node>& weak) : weak(weak) {}
};

struct Node {
  int value;
  Next next;
  Node(int value) : value(value), next(shared_ptr<Node>()) {}
  Node(int value, const shared_ptr<Node>& next) : value(value), next(next) {}
  Node(int value, const weak_ptr<Node>& next) : value(value), next(next) {}
  ~Node() {}
};

shared_ptr<Node> get_cycle_ptr(int cycle_size) {
  shared_ptr<Node> head(new Node(0));
  shared_ptr<Node> prev(head);
  for (int i = 1; i < cycle_size; ++i) {
    shared_ptr<Node> current(new Node(i));
    prev->next.shared = current;
    prev = current;
  }
  prev->next.weak = head;
  return head;
}

void test_weak_ptr() {
  auto sp = shared_ptr<int>(new int(23));
  weak_ptr<int> weak = sp;
  {
    auto shared = shared_ptr<int>(new int(42));
    weak = shared;
    assert(weak.use_count() == 1);
    assert(!weak.expired());
  }
  assert(weak.use_count() == 0);
  assert(weak.expired());

  weak = sp;
  auto wp = weak;
  assert(weak.use_count() == 1);
  auto wwp = std::move(weak);
  assert(weak.use_count() == 0);
  assert(wwp.use_count() == 1);

  auto ssp = wwp.lock();
  assert(sp.use_count() == 2);

  for (int i = 0; i < 1'000'000; ++i) {
    shared_ptr<Node> head = get_cycle_ptr(8);
    shared_ptr<Node> next_head = head->next.shared;
    assert(next_head.use_count() == 2);
    head.reset();
    assert(next_head.use_count() == 1);
  }
}
