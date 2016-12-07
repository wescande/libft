/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 18:15:50 by wescande          #+#    #+#             */
/*   Updated: 2016/12/01 14:38:18 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <locale.h>
#include "../includes/libft.h"
#include "../includes/ft_printf.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
//	void	*ptr;
	int		i1;
	int		i2;
/*	int val;
	int val2;
*/
	setlocale(LC_CTYPE, "");
//	unsigned long int test;
//test = (unsigned long int) -56.4;
//	ft_printf("%lx\n", test);
//	printf("%lx\n", test);
//	printf("eE%e -- %E\n", toto, toto);
//	printf("gG%g -- %G\n", toto, toto);
//	printf("aA%a -- %A\n", toto, toto);
/*	
	double test = 0.045687;

	while (test < 5.0)
	{
	ft_printf("%5.5f\n", test);
	printf("%5.5f\n", test);
	printf("\n");
	test += 0.1;
	}
	// */
/*	
	ft_printf("je {blu}bleu%050.3s{red}red{gre}green%5.6d{eoc}no{whi}white%.10f{pur}purple{eoc}", "ewifew", 456, 548.65);
	printf("je {blu}bleu%050.3s{red}red{gre}green%5.6d{eoc}no{whi}white%.10f{pur}purple{eoc}", "ewifew", 456, 548.65);
// */	
/*
ft_printf("{blu} AAAAAAAAAAAAA\n");
	i1 = ft_printf("%17a\n", 3.54456487458);
	i2 = printf("%17a\n", 3.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);
	i1 = ft_printf("%18a\n", 3.5445648745);
	i2 = printf("%18a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%19a\n", 3.5445648745);
	i2 = printf("%19a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%3a\n", 3.5445648745);
	i2 = printf("%3a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%45a\n", 45683.5445648745);
	i2 = printf("%45a\n", 45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%45a\n", 3.5445648745);
	i2 = printf("%45a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 

	i1 = ft_printf("%.17a\n", 3.54456487458);
	i2 = printf("%.17a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%.18a\n", 3.5445648745);
	i2 = printf("%.18a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.19a\n", 3.5445648745);
	i2 = printf("%.19a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.3a\n", 3.5445648745);
	i2 = printf("%.3a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.45a\n", 45683.5445648745);
	i2 = printf("%.45a\n", 45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.45a\n", 3.5445648745);
	i2 = printf("%.45a\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
*/
/*
ft_printf("{red} ffffffffffffffff\n");
	i1 = ft_printf("%17f\n", 3.54456487458);
	i2 = printf("%17f\n", 3.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%18f\n", 3.5445648745);
	i2 = printf("%18f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%19f\n", 3.5445648745);
	i2 = printf("%19f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%3f\n", 3.5445648745);
	i2 = printf("%3f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%45f\n", 45683.5445648745);
	i2 = printf("%45f\n", 45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%45f\n", 3.5445648745);
	i2 = printf("%45f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//

	i1 = ft_printf("%.17f\n", 3.54456487458);
	i2 = printf("%.17f\n", 3.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.18f\n", 3.5445648745);
	i2 = printf("%.18f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.19f\n", 3.5445648745);
	i2 = printf("%.19f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.3f\n", 3.5445648745);
	i2 = printf("%.3f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.45f\n", 45683.5445648745);
	i2 = printf("%.45f\n", 45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.45f\n", 3.5445648745);
	i2 = printf("%.45f\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.17f\n", 87893.54456487458);
	i2 = printf("%.17f\n", 87893.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%.18f\n", 87893.54456487458);
	i2 = printf("%.18f\n", 87893.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
*/
/*
ft_printf("{gre} gggggggggggggggg\n");
	i1 = ft_printf("%17g\n", 3.54456487458);
	i2 = printf("%17g\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%18g\n", 3.5445648745);
	i2 = printf("%18g\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%19g\n", 3.5445648745);
	i2 = printf("%19g\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%3g\n", 3.5445648745);
	i2 = printf("%3g\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%45g\n", 45683.5445648745);
	i2 = printf("%45g\n", 45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%45g\n", 8788888893.5445648745);
	i2 = printf("%45g\n", 8788888893.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//

	i1 = ft_printf("%.17g\n", 87893.54456487458);
	i2 = printf("%.17g\n", 87893.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("II%.18g\n", 3.5445648745);
	i2 = printf("II%.18g\n",    3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.19g\n", 3.5445648745);
	i2 = printf("%.19g\n",    3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.3g\n", 3.5445648745);
	i2 = printf("%.3g\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.45g\n", 45683.5445648745);
	i2 = printf("%.45g\n", 45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
	i1 = ft_printf("%.45g\n", 3.5445648745);
	i2 = printf("%.45g\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);//
*/
/*
ft_printf("{pur} eeeeeeeeeeeeeeeee\n");
	i1 = ft_printf("%17e\n", 3.54456487458);
	i2 = printf("%17e\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%18e\n", 3.5445648745);
	i2 = printf("%18e\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%19e\n", 3.5445648745);
	i2 = printf("%19e\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%3e\n", 3.5445648745);
	i2 = printf("%3e\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%45e\n", 45683.5445648745);
	i2 = printf("%45e\n", 45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%45e\n", 8788888893.5445648745);
	i2 = printf("%45e\n", 8788888893.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 

	i1 = ft_printf("%.17e\n", 87893.54456487458);
	i2 = printf("%.17e\n", 87893.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%.18e\n", 87893.54456487458);
	i2 = printf("%.18e\n", 87893.54456487458);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("FF%.18e\n", 3.5445648745);
	i2 = printf("FF%.18e\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%.19e\n", 3.5445648745);
	i2 = printf("%.19e\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%.3e\n", 3.5445648745);
	i2 = printf("%.3e\n", 3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf(">>>>>>>>>%.45e\n", 45683.5445648745);
	i2 =    printf(">>>>>>>>>%.45e\n",    45683.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
	i1 = ft_printf("%.45e\n", 3.5445648745);
	i2 = printf("%.45e\n",    3.5445648745);
	printf("COMPARE : {%d}{%d}\n", i1, i2);// 
*/


 /*
	ft_printf("je {blu}bleu%050.3s{red}red{gre}green%5.6d{eoc}no{whi}white%.10f{pur}purple{eoc}", "ewifew", 456, 548.65);
	ft_printf("IIIICCCIIIIIIIICCCIIIII%.75f\n", 3.14);
	printf("%.75f\n", 3.14);
	printf("\n");
	ft_printf("%.75f\n", 1.05);
	printf("%.75f\n", 1.05);
	printf("\n");
	ft_printf("%.75g\n", 3.14);
	printf("%.75g\n", 3.14);
	printf("\n");
	ft_printf("%.75g\n", 1.56405);
	printf("%.75g\n", 1.56405);
	printf("\n");
	ft_printf("%.75g\n", 1.05);
	printf("%.75g\n", 1.05);
	printf("\n");
	ft_printf("%.0g\n", 581.05);
	printf("%.0g\n", 581.05);
	printf("\n");
	ft_printf("%.0g\n", 1.05);
	printf("%.0g\n", 1.05);
	printf("\n");
	ft_printf("%.1g\n", 1.05);
	printf("%.1g\n", 1.05);
	printf("\n");
	ft_printf("%.2g\n", 1.05);
	printf("%.2g\n", 1.05);
	printf("\n");
	ft_printf("%.75a\n", 1.05);
	printf("%.75a\n", 1.05);
	printf("\n");
// */
/*
	i1 = ft_printf("{%010.*b}\n{%.5b}\n\n\n", 5, 4, 4254);
	i1 = ft_printf("{%d}\n{%c} %ld %s %c\n\n\n", 320005, 'A', 2147483647887, "totototot", 'Z');
	i1 = ft_printf("{%%}\n{%Z}\n\n\n", 5, 5);
// */
/*	i1 = ft_printf("FM{%+0.1f}{%F}\n", 42424242.42, 42424242.42);
	i2 = printf("FR{%+0.1f}{%F}\n", 42424242.42, 42424242.42);
	printf("i1 : %d\ni2 : %d\n", i1, i2);// */
/*
	i1 = ft_printf("EM{%e}{%E}\n", 0.042, 42424242.42);
	i2 = printf("ER{%e}{%E}\n", 0.042, 42424242.42);
	printf("i1 : %d\ni2 : %d\n", i1, i2);// */

/*	i1 = ft_printf("gM{%20.5a}{%0a}{%A}{%A}{%a}\n", -3.14, 2.424242, 0.424244242, 42424.424242, 4424224242.424242);
	i2 = printf("gR{%20.5a}{%0a}{%A}{%A}{%a}\n", -3.14, 2.424242, 0.424244242, 42424.424242, 4424224242.424242);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);// */

/*	i1 = ft_printf("EM{%#010.5g}{%+- G}\n", 42424242.42, 42424242.42);
	i2 = printf("ER{%#010.5g}{%+- G}\n", 42424242.42, 42424242.42);
	printf("i1 : %d\ni2 : %d\n", i1, i2);// */


/*	i1 = ft_printf("M@moulitest: %5.x %5.0x\n", 0, 0);
	i2 = printf("R@moulitest: %5.x %5.0x\n", 0, 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);*/

/*	i1 = ft_printf("M%.2c\n", NULL);
	i2 = printf("R%.2c\n", NULL);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);*/
	
/*	i1 = ft_printf("M@moulitest: %c\n", 0);
	i2 = printf("R@moulitest: %c\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);*/
/*	
	i1 = ft_printf("M4%5o\n", 42);
	i2 = printf("R4%5o\n", 42);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
	
	i1 = ft_printf("M0%#o\n", 0);
	i2 = printf("R0%#o\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
	
	i1 = ft_printf("M1%#.O\n", 0);
	i2 = printf("R1%#.O\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
	
	i1 = ft_printf("M2%o\n", 0);
	i2 = printf("R2%o\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
// */	
/*	i1 = ft_printf("Mnull %c and text\n", 0);
	i2 = printf("Rnull %c and text\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);*/
	
/*	i1 = ft_printf("M% c\n", 0);
	i2 = printf("R% c\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);*/
/*
	i1 = ft_printf("M%.c|\n", 65);
	i2 = printf("R%.c|\n", 65);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);

	i1 = ft_printf("M%.c|\n", 0);
	i2 = printf("R%.c|\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
*/
	/*
	i1 = ft_printf("M{%*c}\n", -15, 0);
	i2 = printf("R{%*c}\n", -15, 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
	*/

//	i2 = printf("R{%b}\n", 42);
//	printf("\ni1 : %d\ni2 : %d\n", i1, i2);

/*
	i1 = ft_printf("M%#.3o\n", 1);
	i2 = printf("R%#.3o\n", 1);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
*/
	/*
	i1 = ft_printf("M{%05.Z}\n", 0);
	i2 = printf("R{%05.Z}\n", 0);
	printf("\ni1 : %d\ni2 : %d\n", i1, i2); */

	i1 = ft_printf("M%S\n", L"米");
	i2 = printf("R%S\n", L"米");
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);

	i1 = ft_printf("M%.9S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	i2 = printf("R%.9S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);

	i1 = ft_printf("M%.4S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	i2 = printf("R%.4S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);

	i1 = ft_printf("M%.6S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	i2 = printf("R%.6S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);

	i1 = ft_printf("M%.8S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	i2 = printf("R%.8S\n", L"我是一只猫我是一只猫是一只猫我是一只猫。");
	printf("\ni1 : %d\ni2 : %d\n", i1, i2);
// */
/*	i1 = ft_printf("M%+ .4s\n", "42 is the answer of your mom");
	i2 = printf("R%+ .4s\n", "42 is the answer of your mom");
	printf("i1 : %d\ni2 : %d\n", i1, i2);
	i1 = ft_printf("M%15.4s\n", "i am 42");
	i2 = printf("R%15.4s\n", "i am 42");
	printf("i1 : %d\ni2 : %d\n", i1, i2);
	i1 = ft_printf("M%15.4s\n", "42 is the answer of your mom");
	i2 = printf("R%15.4s\n", "42 is the answer of your mom");
	printf("i1 : %d\ni2 : %d\n", i1, i2);
	i1 = ft_printf("M%#+ 10.5d\n", 789456);
	i2 = printf("R%#+ 10.5d\n", 789456);
	printf("i1 : %d\ni2 : %d\n", i1, i2);
// */
//		i1 = ft_printf("M111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
//		i2 = printf("R111%s333%s555%saaa%sccc\n", "222", "444", "666", "bbb");
//		printf("\ni1 : %d\ni2 : %d\n", i1, i2);
/*				ft_printf("%");
			ft_printf("% ");
			ft_printf("% h");
			ft_printf("%Z");//                              -> "Z"
			      ft_printf("% hZ");//                            -> "Z"
			      ft_printf("%05%"); //                           -> "0000%"
			      ft_printf("%-05%");  //                         -> "%    "
			      ft_printf("% hZ%");    //                       -> "Z"
			      ft_printf("% Z", "test");//                     -> "Z"
			      ft_printf("% Z ", "test");//                    -> "Z "
			      ft_printf("% Z%s", "test"); //                  -> "Ztest"
			      ft_printf("%000   %", "test");//                -> "%"
			      ft_printf("%%%", "test");       //              -> "%"
			      ft_printf("%%   %", "test");      //            -> "%   "
			      ft_printf("%ll#x", 9223372036854775807);//      -> "0x7fffffffffffffff"
			      ft_printf("%010s is a string", "this");   //    -> "000000this is a string"
			      ft_printf("%-010s is a string", "this");    //  -> "this       is a string"
			    ft_printf("%05c", 42);   //                     -> "0000*"
			      ft_printf("% Z", 42);      //                   -> "Z"
			      ft_printf("%0 d", 42);       //                 -> " 42"
			     ft_printf("%0 d", -42);        //               -> "-42"
			      ft_printf("% 0d", 42);           //             -> " 42"
			    ft_printf("% 0d", -42);            //           -> "-42"
			     ft_printf("%5+d", 42);              // /     /    -> "  +42"
			      ft_printf("%5+d", -42);               //        -> "  -42"
			     ft_printf("%-5+d", 42);                 //      -> "+42  "
			      ft_printf("%-0+5d", 42);                 //     -> "+42  "
			      ft_printf("%-5+d", -42);                 //     -> "-42  "
			      ft_printf("%-0+5d", -42);                  //   -> "-42  "
			      ft_printf("%zhd", "4294967296");             // -> "4294967296"
			      ft_printf("%jzd", "9223372036854775807");    // -> "9223372036854775807"
			      ft_printf("%jhd", "9223372036854775807");  //   -> "9223372036854775807"
			      ft_printf("%lhl", "9223372036854775807");    // -> ""
			      ft_printf("%lhlz", "9223372036854775807");   // -> ""
			      ft_printf("%zj", "9223372036854775807");     // -> ""
			      ft_printf("%lhh", "2147483647");             // -> ""
			      ft_printf("%hhld", "128");                   // -> "128"
			      ft_printf("@main_ftprintf: %####0000 33..1..#00d\n", 256);// -> "@main_ftprintf:                               256\n"
			      ft_printf("@main_ftprintf: %####0000 33..1d", 256); //-> "@main_ftprintf:                               256"
			      ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256); //-> "@main_ftprintf: +256      */
	return (0);
}
