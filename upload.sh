export PROG_NUM=1

echo "Upload to classes server Project $PROG_NUM"
cd ..
scp -r ./prog$PROG_NUM cs410368@classes.csc.lsu.edu:~/
cd ./prog$PROG_NUM
