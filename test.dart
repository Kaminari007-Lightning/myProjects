void main() {
   int p1 = 123;
  int p2 = 456;

  int ps = 456;

  if (ps == p1) {
    print("you can buy p1 with: $p1");
  }
  else {
    print("you can buy p2 with: $p2");
  }  

   int p3 = 123;

  switch (p3) {
    case 123:
      {
        print("you can buy p1 with: $p3");
        break;
      }
    case 456:
      {
        print("you can buy p2 with: $p3");
        break;
      }
    case 789:
      {
        print("you can buy p3 with: $p1");
        break;
      }
      default:
  } 

  for (int i = 0; i <= 10; i++) {
    print(i);
  }
  print("there is no 11 number"); 

   String a = "10";
  print(num.parse(a) is int);
}
