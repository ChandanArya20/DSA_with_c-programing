#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int isEnd(int ch);

int strLen( char *str)
{
    int i=0;
    while(str[i]!=0)
        i++;
    return i;
}
void toLowerString(char *str)
{
    int i;
    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='A' && str[i]<='Z')
            str[i]+=32;
        
    }
}
void toUpperString(char *str)
{
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a' && str[i]<='z')
            str[i]-=32;
        
    }
}
int countVowel(char *str)
{
    int i,vowel=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || \
           str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            vowel++;
    }
    return vowel;
}
int countConsonant(char *str)
{
    int i,cons=0;
    for(int i=0;str[i]!='\0';i++)
    {
        if(str[i]=='A' || str[i]=='E' || str[i]=='I' || str[i]=='O' || str[i]=='U' || \
           str[i]=='a' || str[i]=='e' || str[i]=='i' || str[i]=='o' || str[i]=='u')
            continue;
        else
            if(str[i]>='A' && str[i]<='Z' || str[i]>='a' && str[i]<='z')
                cons++;
    }
    return cons;
}
int wordCount(char *str)
{
    int count=0;
    int i;
    for(i=0; str[i]!='\0'; i++)
    {
        if(isEnd(str[i]) && !isEnd(str[i-1]))
        {
            count++;
        }
    }
    if(isEnd(str[i-1])==0)
        count++;
    return count;
}
int isEnd(int ch)
{
    if(ch==' ' || ch=='.' || ch==',' || ch==':' || ch=='-' || ch==';' || ch=='\n')
    {
        return 1;
    }
    return 0;
}
void reverseStr(char *str)
{
    int i,j;
    char temp;
    for(i=0,j=strlen(str)-1; i<j; i++, j--)
    {
        temp=str[i];
        str[i]=str[j];
        str[j]=temp;
    }
}
int strcpr(char *str1, char *str2)
{
    int i;
    for(i=0; str1[i]!='\0' && str2[i]!='\0'; i++)
    {
        if(str1[i]!=str2[i])
            break;
    }
    if(str1[i]==str2[i])
        return 0;
    else if(str1[i]>str2[i])
        return 1;
    else
        return -1;

}
int strcpr2( char *str1 ,char *str2)
{
    int i;
    char ch1, ch2;
    for(i=0; str1[i]!='\0'; i++)
    {
        ch1 = str1[i];
        ch2 = str2[i];
        if(str1[i]>='A' && str1[i]<='Z')
            ch1=str1[i]+32;
        if(str2[i]>='A' && str2[i]<='Z')
            ch2=str2[i]+32;
        if(ch1!=ch2)
            break;
    }
    if(str1[i]==str2[i])
    {
        return 0;
    }
    else if(str1[i]-str2[i]>0)
        return 1;
    else
        return -1;
}
int strPelindrum(char *str)
{
    int i,j;
    for(i=0,j=strlen(str)-1; i<j; i++, j--)
    {
        if(str[i]!=str[j])
            return 0;  
    }
    return 1;
}
void deleteChar(char *str,char ch)
{
    int i,j;
    for(i=0,j=0;str[i]!='\0';i++)
    {
        if(str[i]!=ch)
        {
            str[j]=str[i];
            j++;
        }
           
    }
    str[j]='\0';
}
int str_to_i(char *str)
{
    int i=0,sign,r=0;
    while(str[i]==' ')
        i++;
    sign=(str[i]=='-')? -1 : 1;
    if(str[i]=='-' || str[i]=='+')
        i++;
    while(str[i]>='0' && str[i]<='9')
        r=r*10+(str[i++]-'0');
        
    return sign*r;
    
}
double str_to_d(char *str)
{
    int i=0,j,sign,r=0;
    while(str[i]==' ')
        i++;
    sign=(str[i]=='-')? -1 : 1;
    if(str[i]=='-' || str[i]=='+')
        i++;
    while(str[i]>='0' && str[i]<='9')
        r=r*10+(str[i++]-'0');
    if(str[i]=='.')
    {
        i++;
        j=i;
        while(str[i]>='0' && str[i]<='9')
            r=r*10+(str[i++]-'0');

    }

    return sign*r/pow(10,i-j);
    
}
// int anagram(char *str1, char *str2)
// {
//     if(strlen(str1)==strlen(str2))
//     {
//         for(int i=0;str1[i]!='\0';i++)
//         {
//             for(int j=0;str2[i]!='\0';j++)
//             {
//                 if(str1[i]==str2[i])

//             }
//         }
//     }
// }

