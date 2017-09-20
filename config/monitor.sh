#! /bin/bash
#end=$((SECONDS+3600))
#while [ $SECONDS -lt $end ]; do
while true; do
    INTERVAL=30
    #MEMORY=$(free -m | awk 'NR==2{printf "%.2f%%\t\t", $3*100/$2 }')
    MEMORY=$(free -m | awk 'NR==2{printf "%d\t\t", $3*100/$2 }') #NR==2 当前是第2行时打印
    DISK=$(df -h | awk '$NF=="/"{printf "%s\t\t", $5}') #NF表示分割出来的数量，$NF表示取最末尾元素
    #CPU=$(top -bn1 | grep load | awk '{printf "%.2f%%\t\t\n", $(NF-2)}')
    CPU=$(top -bn1 | grep load | awk '{printf "%.2f\t\t\n", $(NF-2)}')
    if (( $(echo "$CPU > 1.0" |bc -l) ))   # 判定float
    then
        date
        printf "Memory(%%)\tDisk(%%)\t\tCPU(%%)\n"
        echo "$MEMORY$DISK$CPU"
        echo "CPU load over 1.0, here is top 3 cpu use process:"
        echo "======================(begin)========================="
        ps auxh --sort -pcpu  | head -3   #根据CPU占用比例排序, 前3
        printf "======================(end)===========================\n\n"
        INTERVAL=10
    fi

    if [ $MEMORY -ge 90 ]
    then
        date
        printf "Memory(%%)\tDisk(%%)\t\tCPU(%%)\n"
        echo "$MEMORY$DISK$CPU"
        echo "Memory is over 90%, here is top 3 mem use process:"
        echo "========================(begin)======================="
        ps auxh --sort -rss  | head -3  #根据内存占用比例排序, 前3
        printf "========================(end)=========================\n\n"
        INTERVAL=10
    fi
    sleep $INTERVAL
done
