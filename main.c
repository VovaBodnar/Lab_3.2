  #include <Windows.h>
  #include <stdio.h>
  #include <stdlib.h>

  double Func(double x);
  void Method_chord(double a, double b, double EPSILON, int Debug, int Values_Print);
  void Method_bisection(double a, double b, double EPSILON, int Debug, int Values_Print);


int main() {

  int input_A, input_B, input_Epsilon;
  int Metod_Used;
  int Debug, Values_Print;


    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    printf("\n ������� ����� ���������� �������:\n");
    printf("\n   1 - ������� ����������� ������");
    printf("\n   2 - ������� ����");
    do {
          printf("\n �������� ����� : ");
          scanf("%d", &Metod_Used);
    } while (Metod_Used != 1 && Metod_Used != 2);


    printf("\n �� ������� ���� �������� ���������� ? 0-ͳ 1-��� : ");
    scanf("%d", &Debug);
    if (Debug == 1) {
          printf("\n ������� �������� � ������� ���������� ��� ��������� ������, �� ������ ��� :");
          scanf("%d", &Values_Print);
   }

    printf("\n ������ a, b, eps:");
    printf("\n a, b, eps = ");
    scanf("%d %d %fl", &input_A, &input_B, &input_Epsilon);
    printf("\n\n");



    double Start_Time = clock();

    if (Metod_Used == 1) {
          Method_bisection(input_A, input_B, input_Epsilon, Debug, Values_Print);
    } else {
          Method_chord(input_A, input_B, input_Epsilon, Debug, Values_Print);
    }

    printf("\n ���������� ��� �� ���������� = %f Sec\n\n", clock() - Start_Time);

  return 0;
}


double Func(double x) {
  return pow(2.71828, x);
}
void Method_chord(double a, double b, double EPSILON, int Debug, int Values_Print) {

  double x_next = 0;
  double tmp;
  int VhatToDoo;
  int ValuesPrinedCounter;

  do {
    tmp = x_next;
    x_next = b - Func(b) * (a - b) / (Func(a) - Func(b));
    a = b;
    b = tmp;

    if (Debug == 1) {

          printf("root  = %lf\n", x_next);
          ValuesPrinedCounter ++;
          if (ValuesPrinedCounter > Values_Print) {

                printf("\n ��������� ������� �������� � ������� ���������� ��� ��������� ������, �� ������ ��� :");
                printf("\n 0) ���������� � ����� � ������� ��������;");
                printf("\n 1) �������� �������� �� ����, ���� �� ������ �������� ����� �������; ");
                printf("\n 2) ����� �� ��������, ����� ������� ������ �� ����� ��������� �������� ��������� ���������;");
                printf("\n ���� ²���²��: ");

                scanf("\n %d", &VhatToDoo);

                printf("\n");

                if (VhatToDoo == 0) ValuesPrinedCounter = 0;
                if (VhatToDoo == 1) Debug = 0;
                if (VhatToDoo == 2) break;

      }
    }
  } while (abs(x_next - b) > EPSILON);

  printf("\n method_chord = %lf \n\n", x_next);
}
void Method_bisection(double a, double b, double EPSILON, int Debug, int Values_Print) {
  double c = a;
  int VhatToDoo;
  int ValuesPrinedCounter;

    while ((b - a) >= EPSILON) {
          c = (a + b) / 2;
    if (Func(c) == 0.0) {
          break;
    }
    else if (Func(c) * Func(a) < 0) {
          b = c;
    }
    else {
          a = c;
    }

    if (Debug == 1) {

          printf("root  = %lf\n", c);
          ValuesPrinedCounter ++;
          if (ValuesPrinedCounter >= Values_Print) {

                printf("\n ��������� ������� �������� � ������� ���������� ��� ��������� ������, �� ������ ��� :");
                printf("\n 0) ���������� � ����� � ������� ��������;");
                printf("\n 1) �������� �������� �� ����, ���� �� ������ �������� ����� �������; ");
                printf("\n 2) ����� �� ��������, ����� ������� ������ �� ����� ��������� �������� ��������� ���������;");
                printf("\n ���� ²���²��: ");

                scanf("\n %d", &VhatToDoo);

                printf("\n");

                if (VhatToDoo == 0) ValuesPrinedCounter = 0;
                if (VhatToDoo == 1) Debug = 0;
                if (VhatToDoo == 2) break;
      }
    }
  }

  printf("\n method_bisection = %lf\n", c);
}
