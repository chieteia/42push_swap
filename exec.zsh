seq 1 1000 | gshuf | head -n 100 | xargs echo | xargs ./a.out