int n, a = 1, sum = 0;
printf("Enter the last number of this series : ");scanf("%d", &n); 
for (;;) {
printf(" %d^2",a);
sum =sum + (a*a);
a=a+2; 
if (a > n) {
break; 
 }printf(" +");
}printf("%d = %d\n", n, sum);