#include <stdio.h>

/*1		1
2		2
3		3
4		2
5		5
6		3
7		7
8		2
9		3
10		5
11		11
12		3
13		13
14		7
15		5
16		2
17		17
18		3
19		19
20		5
21		7
22		11
23		23
24		3
25		5
26		13
27		3
28		7
29		29
30		5
31		31
32		2
33		11
34		17
35		7
36		3
37		37
38		19
39		13
40		5
41		41
42		7
43		43
44		11
45		5
46		23
47		47
48		3
49		7
50		5
51		17
52		13
53		53
54		3
55		11
56		7
57		19
58		29
59		59
60		5
61		61
62		31
63		7
64		2
65		13
66		11
67		67
68		17
69		23
70		7
71		71
72		3
73		73
74		37
75		5
76		19
77		11
78		13
79		79
80		5
81		3
82		41
83		83
84		7
85		17
86		43
*/



int gcd(int a, int b) 
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
 
}

int pseudo(int r, int n)
{
    /*  Integer N′ in [0, R − 1] such that NN′ ≡ −1 mod R,*/
    
    for(int i = 0; i < r - 1 ; i++)
    {
    

       if(n * i == -1 % r)
       {
           return i;
           break;
       }

    }
    
    return 0;

    
}

void monto(int r, int n)
{
    
        /*what curve are we going to use? The user will give the values */

    int nx;
   
    
    int T;
    
    /*  Integer T in the range [0, RN − 1].*/
    T = (r*n) - 1;

    /*nx must be a pseudo prime*/
    nx = pseudo(r, n);
    
    /*These values will be used as storage for answers*/
    int s, t, m;
    


    
    
    
    /*Integers R and N with gcd(R, N) = 1*/
    /*we will add the one if statement line later*/
    
    
 
 
    if(gcd(r, n) == 1)
    {
        
        /* m ← ((T mod R)N′) mod R*/
        m = ((T % r ) * nx) % r;
        
        /*  t ← (T + mN) / R*/
        t = ((T + (m * n)) / r);
        
        if(t >= n)
        {

        s = t - n;
            
        }
        else
        {
            
        s = t;

        }
        
    }
    
  //  printf("%d, %d, %d",s, n -1, (T * (1 / r)) % n );
    
    if(s <= n - 1 && 0 <= s && s != (int)(T * (1 / r)) % n && s % 2 == 1)
    {
        printf("%d", s);
    }

}

void main()
{
    
    
    /*6, 5 -->  4, 10, 9 --> 8, 13, 11 -->  10 */ 
    monto(7, 6);
    
}
