rm -f log.txt
for file in ./map/*
do
	echo "map passed: $file"
	leaks --atExit -- ./cub3D $file >> log.txt
done
cat log.txt | grep leaked
