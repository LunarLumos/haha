int a, b, c;double result;
printf("  Determine the roots of the quadratic equation ax^2 + bx + c = 0\n");
printf(" Enter your coefficient 'a': ");scanf("%d", &a);
printf("Enter your coefficient 'b': ");scanf("%d", &b);
printf("Enter your coefficient 'c': ");scanf("%d", &c);
result = (b * b) - (4 * a * c);printf("discriminant is %lf !\n", result);
if (result > 0) {
printf("Two real roots!\n");
} else if (result == 0) {
printf(" One real root!\n");
 } else {
printf(" No real roots.\n");
}