savedcmd_/home/sch/a01/main.mod := printf '%s\n'   main.o | awk '!x[$$0]++ { print("/home/sch/a01/"$$0) }' > /home/sch/a01/main.mod
