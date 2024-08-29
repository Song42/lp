savedcmd_/home/sch/little/a08/main.mod := printf '%s\n'   main.o | awk '!x[$$0]++ { print("/home/sch/little/a08/"$$0) }' > /home/sch/little/a08/main.mod
