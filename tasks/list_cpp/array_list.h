class ArrayList {
 private:
  int* memory_;   // сырая память в которой хранятся данные
  int capacity_;  // сколько памяти выделено
  int size_;      // сколько элементов занято

 public:
  ArrayList(int capacity = 2) {
    // тут лучше использовать список-инициализации, изучим потом
    capacity_ = capacity;
    size_ = 0;
    // TODO: выделить память
  }

  /**
   * вставка элемента в конец списка.
   * Если нужно, capacity увеличится в 2 раза.
   *
   * @param value значение, которое надо вставить
   */
  void PushBack(const int& value);

  /**
   * вставка элемента в начало списка.
   * Индексы всех элементы увеличиваются на 1.
   * Если нужно, capacity увеличится в 2 раза.
   *
   * @param value значение, которое надо вставить
   */
  void PushFront(const int& value);

  /**
   * Вставка элемента по индексу.
   * Индексы всех элементов после idx включительно увеличиваются на 1.
   * Если нужно, capacity увеличится в 2 раза.
   *
   * @param value значение, которое надо вставить
   * @param idx индекс вставки
   */
  void Insert(const int& value, int idx);  // вставка элемента после индекса

  /**
   * Удаляет указанный элемент из списка.
   * Если нужно, занимаемая память уменьшится.
   *
   * @param idx индекс элемента, который надо удалить
   */
  void Erase(int idx);

  /**
   * Удаление всех элементов из списка.
   * Память очищается и выделяется новый кусок.
   * - capacity_ выставляется в начальное состояние.
   * - size_ выставляется в ноль
   */
  void Clear();

  /**
   * Возвращает первый элемент массива.
   * Если список пуст, поведение не определено.
   *
   * По сути это array[0]
   *
   * @return int& ссылка на первый элемент.
   */
  int& Front();

  /**
   * Возвращает первый элемент массива.
   * Если список пуст, поведение не определено.
   *
   * Константная версия.
   *
   * По сути это array[0]
   *
   * @return int& ссылка на первый элемент.
   */
  const int& Front() const;

  /**
   * Удаление элемента с конца списка.
   *
   */
  void Pop();

  /**
   * Удаление элемента с начала списка
   *
   */
  void Dequeue();

  /**
   * Возвращает количество элементов в контейнере.
   *
   * @return int количество элементов в контейнере
   */
  int Size() const;

  /**
   * Взятие элемента списка по индексу
   *
   * @param idx индекс
   * @return int значение по индексу в массиве
   */
  int& operator[](int idx);

  /**
   * Взятие элемента списка по индексу без возможности менять элемент.
   *
   * @param idx индекс
   * @return int значение по индексу в массиве
   */
  const int& operator[](int pos) const;

  ~ArrayList() {
    // TODO: почистить память
  }
};