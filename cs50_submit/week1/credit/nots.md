<!-- Thes is note file for my_last_version.c-->
## Nots
### credit project 
##### check cs50 page  [problemset credit](https://cs50.harvard.edu/x/2024/psets/1/credit/)
##### check my code    [my_last_version.c](https://github.com/mosaabdo/local_cs50/blob/main/cs50_submit/credit/my_last_version.c)
##### index
| n | notes | about |
|----|----|----|
| 1 |best way to fex loop | how i can comblet loop without problems
|2 | dont rebet my slef | how i can compress code 
|3 | the / and % | what is / and % and how  i can use it.
-----------------------------
#### Firest Note
in **chech_type** function
````c
19   |     void check_type (long type)
````
from line 24 to 29
```c

24   |     int count_of_filed = 1;
25   |     for(int i=0; i<c; i++)
26   |     {
28   |        c = c/10;
29   |         count_of_filed++;
30   |     }
````
1. delete thes loop and change __count_of_filed__ valu to 2
-  __count_of_filed = 2;__
2. add __count_of_filed++__ to __wihle__ loop
- thes step for count number filed by take __while__ time + count of filde
````c
31   |     int count_of_filed = 2;
32   |     while (type >= 100)
33   |     {
34   |          type /= 10;
35   |          count_of_filed++;
36   |     }
````
----
#### Secand
in **luhan** function
````c
62   |     int luhan(long c)
````
in line 68
````c
68   |     for(int i=0; i<c_valu+10; i++)
````
1. the function in thes line is take a oode and even number and apply luhan algorthim but we have one problem if __i > c_valu__ 
>>..
>>for exm : __i = 9 and c_valu = 8__ 
>>in thes senario __for loop__ skep it last loop and now we have a problem
>>for that we add 10 in __c_valu__
>> __i < c_valu+10__
>>but we have a other way and best
>> for __for loop__ accept boolian valu 0 or 1 true or false we can decremint __c_valu__ for 0 and __c_valu__ = 0 we can end loop
>> you can use __for(;c_valu;)__
>>..


- for that we can replace this line __for(int i =0; i < c_valu; i++)__ and add this line __for(;c_valu;)__
````c
 68   |  // for(int i=0; i<c_valu+10; i++)
 69   |     for(;c_valu;)
````
----
#### last thing
##### what is / and %

- the __/__ symble is division
>>..
>>for exm : 
__in intger valu__ 
>>..
````c
    int x = 12:
    x = x / 10
    printf("x = %i\n"); 
````
the autbot is 
>>..
>>   $ ./ code
>>
>>   $ x = 1
>>..

>>..
>>__but in float vlalu__
````c
    int x =12;
    x = x /10;
     printf("x = %i\n"); 
````
the autbot is  
>>..
>>   $ ./ code
>>
>>   $ x = 1.20000
>>..

__in my code we use / for change c_valu evrey loop__

- __the % symble is modulo__
>>..
>>for exm :  
````c
    int x = 12:
    x = x % 10
    printf("x = %i\n"); 
````
the autbot is :
>>..
>>   $ ./ code
>>
>>   $ x = 2
>>..

__in my code we use % to take last number of c_valu evrey loop__



----