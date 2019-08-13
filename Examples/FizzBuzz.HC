
U0 FizzBuzz()
{
U8 i;
for (i = 1; i <= 100; i++) {
  if (!(i % 15))
    "FizzBuzz\n";
  else if (!(i % 3))
    "Fizz\n";
  else if (!(i % 5))
    "Buzz\n";
  else
    "%d\n", i;
}
}

FizzBuzz;

