dotest() {
    for i in {1..10}; do python3 update_locations.py $1 $2 | sed -n 's/Mean time per coordinate: //p' >> out.txt; done
    average $1
}
average (){
    {  echo $1 ; awk '{ sum += $1; n++ } END { if (n > 0) print sum / n; }' out.txt ; } |  awk -vRS="\n" -vORS="\t" '1' >> data.txt
    echo \ >> data.txt
    rm out.txt
}
tabs 4
dotest 28 200000
dotest 56 100000
dotest 112 50000
dotest 224 25000