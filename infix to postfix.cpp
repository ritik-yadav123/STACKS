#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define MAX 100 
int stack[MAX];
int pop();
void push(char);
int isEmpty();
int isFull();
int top=-1;
char infix[MAX],postfix[MAX];
void  intopost();
void  print();
int precedence(char);
int posteval();
int isEmpty(){if(top==-1)return 1;
              else return 0;} 
int isFull (){ if(top==MAX-1)
              return 1;
             else 
			 return 0;}   
void push(char c){  
         if(isFull()){printf("overflow");
         exit(1);}
		 top++;
		 stack[top]=c; }
int pop(){char c;
           if(isEmpty()){printf("underflow");exit(1);}
           c=stack[top];
           top--;
		   return c;}
int main(){int result;
           printf("enter infix expression");
           gets(infix);
           intopost();
		   print();
		  result=posteval();
		   
		   printf("result is");
		   printf("%d\n",result);}
void intopost(){int i,j=0;
                char symbol,next;
                for(i=0;i<strlen(infix);i++){
					symbol=infix[i];
	switch(symbol){case '(':push(symbol);
	                        break;
	               case')':while((next=pop())!='(')
				                  postfix[j++]=next;
								  break;
		            case'+':
		            case'-':
		            case'*':
		            case'/':
		            case'^':
		            while(!isEmpty()&&precedence(stack[top])>=precedence(symbol))
		               postfix[j++]=pop();
		               push(symbol);
		               break;
		             default: postfix[j++]=symbol; 	}}	
	                while(!isEmpty())
	                  postfix[j++]=pop();
	                  postfix[j]='\0';}
int precedence(char symbol){
                    switch(symbol){case'^':return 3;
                                   case'*':
                                   case'/':
                                            return 2;
									case'+':
									case'-':
									        return 1;
									default:return 0;}}
void print(){int  i=0;
                   while(postfix[i]){printf("%c",postfix[i++]);
                  }printf("\n");}
int posteval(){int i,a,b;
                for(i=0;i<strlen(postfix);i++){
                	if(postfix[i]>='0'&&postfix[i]<='9'){
                		push(postfix[i]-'0');}
                	else {a=pop();
                	      b=pop();
                	      switch(postfix[i]){case'+':push(a+b);
                	                                  break;
                	                         case'-':push(b-a);
                	                                  break;         
						                      case'*':push(b*a);
                	                                  break;  
					                          case'/':push(b/a);
                	                                  break;         
				                               case'^':push(pow(b,a));
                	                                  break;            	}  }}   return pop(); }
                
																	 													  		   
