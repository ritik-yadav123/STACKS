#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100 
char stack[MAX];
char pop();
void push(char);
int isEmpty();
int isFull();
int top=-1;
int checkbalanced(char*);
int matchchar(char,char);
int main(){char expr[MAX];
           int balanced;
           printf("Enter expression");
           gets(expr);
            balanced=checkbalanced(expr);
           if(balanced==1)printf("Valid expression");
            else printf("Invalid");}
int isEmpty(){if(top==-1)return 1;
              else return 0;} 
int isFull (){ if(top==MAX-1)
              return 1;
             else 
			 return 0;}   
int matchchar(char a,char b) {if(a== '[' &&b== ']') return 1;
                             if(a== '{' &&b== '}')return 1;
                             if(a== '(' &&b== ')')return 1;
							 return 0;}             			            
 int checkbalanced(char*s){char temp;
        int i;
        for(i=0;i<strlen(s);i++){
 	     if(s[i]=='['||s[i]=='{'||s[i]=='(')
		   push(s[i]);
 	    if(s[i]==']'||s[i]=='}'||s[i]==')'){
 		if(isEmpty()){
		 printf("rgt bracket>lft bracket\n");return 0;}
 		else{
		 temp=pop();
 		if(!matchchar(temp,s[i])){printf("mismatch bracket\n");return 0;}} }}
 		 if(isEmpty()){printf("bracket balanced\n");return 1;}
 		else{printf("lft bracket>rgt bracket\n");
		 return 0;}}
 		
void push(char c){  
         if(isFull()){printf("overflow");
         exit(1);}
		 top++;
		 stack[top]=c; }
char pop(){char c;
           if(isEmpty()){printf("underflow");exit(1);}
           c=stack[top];
           top--;
		   return c;}
          



