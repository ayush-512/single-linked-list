#include <stdio.h>
#include <stdlib.h>
typedef struct singlelist{
    int info;
    struct singlelist *next;
} node;
node *create_slist(node *,int);
void display_slist(node *);
int max_slist(node *);
int search_slist(node *,int);
node *insert_first(node *,int);
node *insert_last(node *,int);
node *insert_mid(node *,int,int);
node *delete_first(node *);
node *delete_last(node *);
node *delete_mid(node *,int);
void sort_slist(node *);
node *reverse_slist(node *);
node *merge_slist(node *,node *);
int main()
{   node *start=NULL;
    node *start2=NULL;
    int num,choice,pos;
    printf("Single Linked List Operations:\n");
    while(1)
    {   printf("\n1.Create\n");
        printf("2.Display\n");
        printf("3.Max element\n");
        printf("4.Search element\n");
        printf("5.Insert first new node\n");
        printf("6.Insert last new node\n");
        printf("7.Insert mid new node\n");
        printf("8.Delete first node\n");
        printf("9.Delete last node\n");
        printf("10.Delete mid node\n");
        printf("11.Sort\n");
        printf("12.Reverse\n");
        printf("13.Merge\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {   case 1:
                printf("Enter info:");
                scanf("%d",&num);
                start=create_slist(start,num);
                break;
            case 2:
                display_slist(start);
                break;
            case 3:
                printf("Max element: %d\n", max_slist(start));
                break;
            case 4:
                printf("Enter number to be searched: ");
                scanf("%d", &num);
                if(search_slist(start, num))
                    printf("Element %d found\n", num);
                else
                    printf("Element %d not found\n", num);
                break;
            case 5:
                printf("Enter no to be inserted:");
                scanf("%d",&num);
                start=insert_first(start,num);
                break;
            case 6:
                printf("Enter no to be inserted:");
                scanf("%d",&num);
                insert_last(start,num);
                break;
            case 7:
                printf("Enter no to be inserted:");
                scanf("%d",&num);
                printf("Enter position for insertion:");
                scanf("%d",&pos);
                insert_mid(start,num,pos);
                break;
            case 8:
                start=delete_first(start);
                break;
            case 9:
                start=delete_last(start);
                break;
            case 10:
                printf("Enter position of deletion:");
                scanf("%d",&pos);
                start=delete_mid(start,pos);
                break;
            case 11:
                sort_slist(start);
                break;
            case 12:
                start=reverse_slist(start);
                break;
            case 13:
                start=merge_slist(start,start2);
                break;
            default:
                printf("invalid choice\n");  }
    }return 0;
}
node *create_slist(node *start,int num)
{   node *newnode, *temp;
    newnode=(node*)malloc(sizeof(node));
    newnode->info=num;
    newnode->next=NULL;
    if(start==NULL)
    {   start=newnode;}
    else
    {   temp=start;
        while(temp->next != NULL)
        {   temp=temp->next;}
        temp->next=newnode;   }
    return (start);
}
void display_slist(node *start)
{   node *temp;
    if(start==NULL)
    {   printf("List is empty");}
    else
    {   printf("List elements are \n");
        temp=start;
        while(temp !=NULL)
        {   printf("%d\t",temp->info);
            temp=temp->next;   }   }
}
int max_slist(node *start)
{   int max;
    node *temp;
    max=start->info;
    temp=start->next;
    while(temp !=NULL)
    {   if(temp->info > max)
        {   max=temp->info; }
        temp=temp->next;   }
    return (max);
}
int search_slist(node *start,int num)
{   node *temp;
    temp=start;
    while(temp !=NULL)
    {   if(temp->info ==num)
        {   return (1); }
        temp=temp->next;    }
    return (0);
}
node *insert_first(node *start,int num)
{   node *newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->info=num;
    newnode->next=start;
    start=newnode;
    return (start);
}
node *insert_last(node *start,int num)
{   node *newnode, *temp;
    newnode=(node*)malloc(sizeof(node));
    newnode->info=num;
    newnode->next=NULL;
    if(start==NULL)
    {   start=newnode;  }
    else
    {   temp=start;
        while(temp->next != NULL)
        {   temp=temp->next;    }
        temp->next=newnode; }
    return (start);
}
node *insert_mid(node *start,int num,int pos)
{   node *temp,*newnode;
    newnode=(node*)malloc(sizeof(node));
    newnode->info=num;
    newnode->next=NULL;
    if(start==NULL)
    {   start=newnode;  }
    else
    {   temp=start;
        for(int i=0;i<pos-1;i++)
        {   temp=temp->next;    }
        newnode->next=temp->next;
        temp->next=newnode; }
    return (start);
}
node *delete_first(node *start)
{   node *temp;
    if(start==NULL)
    {   printf("list is empty no deletion operation is perfomed");}
    else
    {   temp=start;
        start=start->next;
        free(temp); }
    return (start);
}
node *delete_last(node *start)
{   node *prev,*dnode;
    if(start==NULL)
    {   printf("list is empty");    }
    else
    {   prev=NULL;
        dnode=start;
        if(dnode->next==NULL)
        {   start=dnode->next;  }
        else
        {   while(dnode->next !=NULL)
            {   prev=dnode;
                dnode=dnode->next;  }
            prev->next=dnode->next; }
        free(dnode);    }
    return (start);
}
node *delete_mid(node *start,int pos)
{   node *prev,*dnode;
    if(start==NULL)
    {   printf("List is empty");
        return start;
    }else
    {   prev=NULL;
        dnode=start;
        if(dnode->next==NULL)
        {   start=dnode->next;
        }else
        {   for(int i=1;i<= pos-1;i++)
            {   prev=dnode;
                dnode=dnode->next;  }
            prev->next=dnode->next; }
        free(dnode);    }
    return (start);
}
void sort_slist(node *start)
{   node *temp, *nextnode;
    int t;
    for(temp=start;temp->next !=NULL;temp=temp->next)
    {   for(nextnode=temp->next;nextnode !=NULL;nextnode=nextnode ->next)
        {   if(temp->info > nextnode->info)
            {   t=temp->info;
                temp->info=nextnode->info;
                nextnode->info=t;   }   }   }
}
node *reverse_slist(node *start)
{   node *prev, *temp, *newnode,*nextnode;   
    prev=NULL;
    temp=start;
    while(temp !=NULL)
    {   nextnode=temp->next;
        temp->next=prev;
        prev=temp;
        temp=nextnode;  }
    start=prev;
    return (start);
}
node *merge_slist(node *start1,node *start2)
{   node *temp1, *temp2, *start;
    start=NULL;
    temp1=start1;
    temp2=start2;
    while(temp1 !=NULL && temp2 !=NULL)
    {   if(temp1->info < temp2->info)
        {   start=create_slist(start,temp1->info);
            temp1=temp1->next;  }
        else if(temp1->info > temp2->info)
        {   start=create_slist(start,temp2->info);
            temp2=temp2->next;  }
        else
        {   start=create_slist(start,temp1->info);
            temp1=temp1->next;
            temp2=temp2->next;  }
    }
    if(temp1==NULL)
    {   while(temp2!=NULL)
        {   start=create_slist(start,temp2->info);
            temp2=temp2->next;  }   }
    else
    {   while(temp1!=NULL)
        {   start=create_slist(start,temp1->info);
            temp1=temp1->next;  }   }
    display_slist(start);
    return start; 
}