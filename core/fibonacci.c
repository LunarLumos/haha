int a = 0, b = 1, next;printf("Fibonacci numbers between 65 and 100:\n");
for (;;) {
if (a >= 1 && a <= 100) {
printf("%d ", a);
}
next = a + b;a = b;b = next;
 if (a > 100) {
break;
}
}