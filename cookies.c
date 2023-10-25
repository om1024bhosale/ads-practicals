#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head;

int c=0;

int insert_end(int val)
{
  struct node *newnode,*temp;
  newnode=malloc(sizeof(struct node));
  newnode->data=val;
  newnode->next=NULL;
  temp=head;

  while(temp->next!=NULL)
  {
    temp=temp->next;
  }

  temp->next=newnode;
}

void display()
{
    struct node *ptr;
    ptr=head;

    printf("\nValues are:\n");

    while(ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}

void del()
{
    struct node *temp;
    if(head==NULL)
    {
        return;
    }
    
    temp=head;
    head=head->next;
    free(temp);
}
void sort()
{
    struct node *current=head, *index=NULL;
    int temp;
    if(head==NULL)
    {
        return;
    }
    else{
        while(current!=NULL)
        {
            index=current->next;
             
             while(index!=NULL)
             {
                if(current->data > index->data)
                {
                        temp = current->data;  
                        current->data = index->data;  
                        index->data = temp;  
                }

                index=index->next;
             }

             current=current->next;
        }
    }
}
void ans(int k)
{
    int s;
    struct node *temp;
    temp=head;

    if(temp->data < k)
    {
        s=temp->data + (2*temp->next->data);
        
        del();
        del();
        insert_end(s);
        sort();
        ans(k);
        // printf("\nHii..\n");
        c++;
    }
    else{
        return;
    }

   
}


int main()
{
    int n;
    int k;
    printf("Enter the size of Linked list:");
    scanf("%d",&n);

    printf("\nEnter the value of K:");
    scanf("%d",&k);

   struct node *newnode;
   newnode=malloc(sizeof(struct node));

   int val;
   printf("\nEnter the value to insert in linked list:");
   scanf("%d",&val);

   newnode->data=val;
   newnode->next=NULL;
   head=newnode;

   
   for(int i=0; i<n-1; i++)
   {
    printf("\nEnter the value to insert in linked list:");
    scanf("%d",&val);
    insert_end(val);
   }

//    display();
//    sort();
//    display();

printf("Entered All Cookies:");
display();
ans(k);
printf("\nAfter Operation Performed :");
display();
 printf("\nHow many step are required: %d",c);

    return 0;
}
