# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 11:13:55 by tmaraval          #+#    #+#              #
#    Updated: 2018/01/12 11:29:28 by tmaraval         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ROUGE="$(tput bold ; tput setaf 1)"
VERT="$(tput bold ; tput setaf 2)"
JAUNE="$(tput bold ; tput setaf 3)"
BLEU="$(tput bold ; tput setaf 4)"
CYAN="$(tput bold ; tput setaf 6)"
RESETCOLOR="$(tput sgr0)"
PRINTDEBUG=1

cmpdiff()
{
	diff -U 3 ../printf.out ../ft_printf.out > out.txt
	if [ $? -ne 0 ]; then
	    echo "${ROUGE}[KO]${RESETCOLOR} DIFF KO";
	else
		echo "${VERT}[OK]${RESETCOLOR} DIFF OK"
	fi
}

printdebug()
{
	if [ $PRINTDEBUG -eq 1 ]
	then
		echo "${CYAN}DEBUG :${RESETCOLOR}"
		if [ -s out.txt ]
		then
			cat out.txt
		else
			echo "${VERT}DIFF output is empty :)${RESETCOLOR}"
		fi
	fi
}

echo "${VERT}#################################################${RESETCOLOR}"
echo "${VERT}#               printf tester                   #${RESETCOLOR}"
echo "${VERT}#                                               #${RESETCOLOR}"
echo "${VERT}#                                               #${RESETCOLOR}"
echo "${VERT}#   2018                       by : tmaraval    #${RESETCOLOR}"
echo "${VERT}#                                               #${RESETCOLOR}"
echo "${VERT}#################################################${RESETCOLOR}"

gcc test_main.c test_parser.c test_convert.c ../libftprintf.a ../libft/libft.a 2> /dev/null
./a.out 1 > printf.out
./a.out 2 > ft_printf.out
cmpdiff
printdebug
echo "Now i'm trying to segfault your printf"
./a.out 3
