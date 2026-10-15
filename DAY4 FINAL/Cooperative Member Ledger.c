#include<stdio.h>
typedef struct 
{
    char village[50];
    int pincode;
}Address;

typedef struct
{
    int id;
    char name[50];
    float share_capital;
    Address address;

}Member;
int main()
{
    int n;
    printf("Enter the number of members:\n");
    scanf("%d",&n);
    if(n<=0)
    {
        printf("Invalid Count\n");
        return 1;
    }

    Member members[n];

    for(int i=0;i<n;i++){
        printf("Enter the details of %d:\n",i+1);
        printf("ID:\n");
        scanf("%d",&members->id);

        printf("Name:\n");
        scanf("%s",&members->name);

        printf("Share captial:\n");
        scanf("%f",&members->share_capital);

        printf("Village:\n");
        scanf("%s",&members->address.village);

        printf("Pincode:\n");
        scanf("%d",&members->address.pincode);
    }

    printf("\n-----MEMBER DETAILS------\n");
    for(int i=0;i<n;i++)
    {
        printf("ID: %d\n",members->id);
        printf("Name: %s\n",members->name);
        printf("Share capital: %.2f\n",members->share_capital);
        printf("Village: %s\n",members->address.village);
        printf("Pincode: %d\n",members->address.pincode);
        
    }

    float total_share_captial =0;
    for(int i=0;i<n;i++)
    {
        total_share_captial += members->share_capital;
    }

    printf("Total share capital: %.2f\n",total_share_captial);

    int max_share_capital_index = 0;
    for(int i=1;i<n;i++)
    {
        if(members->share_capital > members[max_share_capital_index].share_capital)
        {
            max_share_capital_index = i;
        }
    }

    printf("Member with highest share capital:\n");
    printf("ID: %d\n",members[max_share_capital_index].id);
    printf("Name: %s\n",members[max_share_capital_index].name);
    printf("Share capital: %.2f\n",members[max_share_capital_index].share_capital);

    return 0;
}