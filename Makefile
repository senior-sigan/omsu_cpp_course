all: build

build:
	bundle exec jekyll build

server:
	bundle exec jekyll serve

clean:
	rm -rf _site
	rm -rf .jekyll-cache
	rm _includes/notes_graph.json