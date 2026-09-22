#include<stdio.h>
#include<math.h>
#include<string.h>

void SortString(char *str){

	char temp;
	int i,j;
	int len = strlen(str);
	for(i = 0 ; i < len-1 ; i++){

		for( j = i+1 ; j < len ; j++){

			if(str[i]>str[j]){

				temp = str[j];
				str[j]=str[i];
				str[i]=temp;
			}
		}
	}
}
int main(){
	
	int n,i;
	
	printf("Enter the value of n : \n");
	scanf("%d",&n);
	
	char word[n][50];
	
	printf("Enter the value of string: \n");
	for(i = 0 ; i<n ; i++){
		
		scanf("%s", word[i]);
	}
	
	
	int num = (rand() % (n));

	printf("Randon string : %s\n", word[num]);

	char name[50];
	printf("Enter the value of anagaram name as per random name: \n");
	scanf("%s", name);

	int length1 = strlen(name);
	int length2 = strlen(word[num]);

	if(length1 != length2){

		printf("These two strings are not anagram.");
	}

	SortString(word[num]);
	SortString(name);

	if(strcmp(name,word[num]) == 0){

		printf("YES,It's an anagram");
	}
	else{

		printf("No,It's not.");
	}
	return 0;
}