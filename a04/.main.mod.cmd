savedcmd_/home/sch/a04/main.mod := printf '%s\n'   main.o | awk '!x[$$0]++ { print("/home/sch/a04/"$$0) }' > /home/sch/a04/main.mod
