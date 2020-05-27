#include<stdio.h> 
#include<stdlib.h> 
#define LEN sizeof(struct node) 
typedef struct node 
{ 
 int stackcode; 
 int orderid; 
   float price; 
   int quantity; 
  char type; 
 struct node *next; 
 
}Stack, *stack; 
 
stack buy, sell; 
stack b, s; 
stack b1, s1; 
stack q, p; stack q1, p1; 
int stock_code, num; float money; char stock_type; 
int order = 1; 
void fun1() 
{ 
 b = buy; s = sell; b1 = b->next; s1 = s->next; 
   scanf("%d %f %d %c", &stock_code, &money, &num, &stock_type); 
  printf("orderid: %04d\n", order++); 
    if (stock_type == 'b') 
 { 
      while (s1 != NULL) 
     { 
          if (money >= s1->price) 
          { 
              if (stock_code == s1->stackcode) 
                { 
                  if (num == s1->quantity) 
                    { 
                      printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (money + s1->price) / 2, num, order - 1, s1->orderid); 
                        num = 0; 
                       s->next = s1->next; 
                      free(s1); s1 = s->next; break; 
                  } 
                  else if (num < s1->quantity) 
                 { 
                      printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (money + s1->price) / 2, num, order - 1, s1->orderid); 
                        s1->quantity -= num; 
                        num = 0; 
                       break; 
                 } 
                  else if (num>s1->quantity) 
                   { 
                      printf("deal--price:%6.1f  quantity:%4d  buyorder:%04d  sellorder:%04d\n", (money + s1->price) / 2, s1->quantity, order - 1, s1->orderid); 
                        num -= s1->quantity; 
                        s->next = s1->next; 
                      free(s1); 
                      s1 = s->next; 
                       continue; 
                  } 
              } 
              else 
               { 
                  s = s->next; s1 = s->next; continue; 
             } 
          } 
          else 
               break; 
     } 
      if (num != 0) 
      { 
          q = buy; p = q->next; 
           while (p) 
          { 
              if (money > p->price) 
                { 
                  stack pnew = (stack)malloc(LEN); pnew->orderid = order - 1; pnew->price = money; pnew->quantity = num; pnew->stackcode = stock_code; pnew->type = stock_type; 
                   q->next = pnew; pnew->next = p; 
                  break; 
             } 
              else 
               { 
                  q = q->next, p = q->next; 
                } 
          } 
          if (p == NULL) 
         { 
              stack pnew = (stack)malloc(LEN); pnew->orderid = order - 1; pnew->price = money; pnew->quantity = num; pnew->stackcode = stock_code; pnew->type = stock_type; 
               q->next = pnew; pnew->next = NULL; 
           } 
      } 
} 
  if (stock_type == 's') 
 { 
      while (b1 != NULL) 
     { 
          if (money <= b1->price) 
          { 
              if (stock_code == b1->stackcode) 
                { 
                  if (num == b1->quantity) 
                    { 
                      printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (money + b1->price) / 2, num, order - 1, b1->orderid); 
                        num = 0; 
                       b->next = b1->next; 
                      free(b1); b1 = b->next; break; 
                  } 
                  else if (num < b1->quantity) 
                 { 
                      printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (money + b1->price) / 2, num, order - 1, b1->orderid); 
                        b1->quantity -= num; 
                        num = 0; 
                       break; 
                 } 
                  else if (num>b1->quantity) 
                   { 
                      printf("deal--price:%6.1f  quantity:%4d  sellorder:%04d  buyorder:%04d\n", (money + b1->price) / 2, b1->quantity, order - 1, b1->orderid); 
                        num -= b1->quantity; 
                        b->next = b1->next; 
                      free(b1); b1 = b->next; 
                     continue; 
                  } 
              } 
              else 
               { 
                  b = b->next; b1 = b->next; continue; 
             } 
          } 
          else 
               break; 
     } 
      if (num != 0) 
      { 
          q = sell; p = q->next; 
          while (p) 
          { 
              if (money < p->price) 
                { 
                  stack pnew = (stack)malloc(LEN); pnew->orderid = order - 1; pnew->price = money; pnew->quantity = num; pnew->stackcode = stock_code; pnew->type = stock_type; 
                   q->next = pnew; pnew->next = p; 
                  break; 
             } 
              else 
               { 
                  q = q->next, p = q->next; 
                } 
          } 
          if (p == NULL) 
         { 
              stack pnew = (stack)malloc(LEN); pnew->orderid = order - 1; pnew->price = money; pnew->quantity = num; pnew->stackcode = stock_code; pnew->type = stock_type; 
               q->next = pnew; pnew->next = NULL; 
           } 
      } 
  } 
} 
 
void fun2() 
{ 
 scanf("%d", &stock_code); 
  p = buy; q = p->next; p1 = sell; q1 = p1->next; 
  printf("buy orders:\n"); 
   while (q) 
  { 
      if (q->stackcode == stock_code) 
         printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",q->orderid,q->stackcode,q->price,q->quantity,q->type); 
     p = p->next; q = p->next; 
    } 
  printf("sell orders:\n"); 
  while (q1) 
 { 
      if (q1->stackcode == stock_code) 
            printf("orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q1->orderid, q1->stackcode, q1->price, q1->quantity, q1->type); 
       p1 = p1->next; q1 = p1->next; 
    } 
} 
 
void fun3() 
{ 
 int id; 
    int flag1 = 0, flag2 = 0; 
  scanf("%d", &id); 
  p = buy; q = p->next; p1 = sell; q1 = p1->next; 
  while (q&&!flag1) 
  { 
      if (q->orderid == id) 
       { 
          printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n",q->orderid,q->stackcode,q->price,q->quantity,q->type); 
           p->next = q->next; free(q); flag1 = 1; break; 
        } 
      else 
       { 
          p = p->next; q = p->next; 
        } 
  } 
  while (q1&&!flag2&&!flag1) 
 { 
      if (q1->orderid == id) 
      { 
          printf("deleted order:orderid: %04d, stockid:%04d, price: %6.1f, quantity: %4d, b/s: %c\n", q1->orderid, q1->stackcode, q1->price, q1->quantity, q1->type); 
         p1->next = q1->next; free(q1); flag2 = 1; break; 
     } 
      else 
       { 
          p1 = p1->next; q1 = p1->next; 
        } 
  } 
  if (!flag1&&!flag2) 
    { 
      printf("not found\n"); 
 } 
} 
int main() 
{ 
   //freopen("3.txt", "r", stdin); 
    buy = (stack)malloc(LEN); buy->next = NULL; 
 sell = (stack)malloc(LEN); sell->next = NULL; 
 
  int opcode; 
    while (1) 
  { 
      scanf("%d", &opcode); 
      if (opcode == 0) 
           break; 
     switch (opcode) 
        { 
      case 1:fun1(); break; 
      case 2:fun2(); break; 
      case 3:fun3(); break; 
      } 
  } 
  return 0; 
}  
