export PROG_NUM=1

echo "Submitting Project $PROG_NUM"
~cs4103_chf/bin/p_copy $PROG_NUM

echo "Verifying Project $PROG_NUM"
~cs4103_chf/bin/verify $PROG_NUM
