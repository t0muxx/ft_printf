# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    start.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tmaraval <tmaraval@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 11:13:55 by tmaraval          #+#    #+#              #
#    Updated: 2018/01/16 15:48:31 by tmaraval         ###   ########.fr        #
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
	diff -U 3 printf.out ft_printf.out > out.txt
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

gcc test_main.c test_parser.c test_convert.c ../libftprintf.a 2> /dev/null
echo "test convertion basique"
./a.out 1 > printf.out
./a.out 2 > ft_printf.out
cmpdiff
printdebug
echo "test precision"
./a.out 6 > printf.out
./a.out 7 > ft_printf.out
cmpdiff
printdebug
echo "test largeur de champ + precision"
./a.out 8 > printf.out
./a.out 9 > ft_printf.out
cmpdiff
printdebug
echo "test largeur de champ + precision + flag moins"
./a.out 10 > printf.out
./a.out 11 > ft_printf.out
cmpdiff
printdebug
echo "test largeur de champ + precision + flag moins + flag sharp"
./a.out 13 > printf.out
./a.out 14 > ft_printf.out
cmpdiff
printdebug
echo "Test avec plusieurs argument"
./a.out 15 > printf.out
./a.out 16 > ft_printf.out
cmpdiff
printdebug
echo "Test special"
./a.out 17 > printf.out
./a.out 18 > ft_printf.out
cmpdiff
printdebug
echo "Test char"
./a.out 19 > printf.out
./a.out 20 > ft_printf.out
cmpdiff
printdebug
echo "test affichage pointeur."
./a.out 12
echo "Now i'm trying to segfault your printf"
./a.out 3 > /dev/null
if [ $? -ne 0 ]; then
	echo "${ROUGE}[KO]${RESETCOLOR}";
else
	echo "${VERT}[OK]${RESETCOLOR}"
fi
