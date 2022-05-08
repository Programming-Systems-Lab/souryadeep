for i in {1..100}; do siege -c 1 -r 1 http://127.0.0.1:9001/index20.html >> tmp.txt; done
