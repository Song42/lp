savedcmd_/home/sch/a09/mounts.mod := printf '%s\n'   mounts.o | awk '!x[$$0]++ { print("/home/sch/a09/"$$0) }' > /home/sch/a09/mounts.mod
