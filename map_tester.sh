rm -f log.txt
for file in ./bad_map/*
do
	echo "map passed: $file"
	leaks --atExit -- ./cub3d $file >> log.txt
done
cat log.txt | grep leaked
