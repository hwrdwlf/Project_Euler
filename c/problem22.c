#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

What is the total of all the name scores in the file?)

*/

int helper(void) {
	// Based on the description of the problem set this constant
	int lines = 5000;
	int max_line_length = 100;
	char** words = (char** )malloc(sizeof(char* ) * lines);

	if(words == NULL) {
		fprintf(stderr, "Out of memory. Cannot allocate memory to array words\n");
		exit(1);
	}

	FILE* fp = fopen("p022_names.txt", "r");
	if(fp == NULL){
		fprintf(stderr, "Error opening file.\n");
		exit(2);
	}
	
	int i;
	for(i=0; 1; i++){
		if(i >= lines){
			int new_size;
			new_size = lines * 2;
			words = (char** )realloc(words, sizeof(char*) * new_size);
				
			if(words == NULL) {
				fprintf(stderr, "Out of memory reallocating memory of arry word\n.");
				exit(3);
			}

			lines = new_size;
		}
		words[i] = malloc(max_line_length);
		if(words[i] == NULL) {
			fprintf(stderr, "Out of memory allocating new index of array words\n");
		}

		if(fgets(words[i], max_line_length-1, fp) == NULL) {
			break;
		}

		/* Remove CR OR LF at end of line */
		for(int j = strlen(words[i])-1; j >= 0 && (words[i][j] == '\n' || words[i][j] == '\r'); j--){
			words[i][j+1] = '\0';
		}
	}
	fclose(fp);
	
	for(int j = 0; j < 20; j++){
		printf("%s\n", words[j]);
	}

	/* Free up allocated memory */
	for(; i >= 0; i--) {
		free(words[i]);
	}
	free(words);
	return 0;
}

char* remove_quotes(char* string) {
	int j = 0;
	int str_len = strlen(string);
	for (int i = 0; i < str_len; i ++) {
            if (string[i] != '"' && string[i] != '\\') { 
                 string[j++] = string[i];
            } else if (string[i+1] == '"' && string[i] == '\\') { 
                 string[j++] = '"';
            } else if (string[i+1] != '"' && string[i] == '\\') { 
                 string[j++] = '\\';
            }
	}	
	string[j] = '\0';
	return string;
}

int character_to_int(char* string) {
	int str_len = strlen(string);
	int total = 0;
	for(int i = 0; i < str_len; i++) {
		int j = string[i] - '0';
		total = total + j;
	}

	return total;
}

typedef struct {
    int size;
    char **keys;
    char **values;
} Hash;

struct node {
	char* key;
	char* value;
	struct node* next;
	int index;
};

struct list {
	struct node* head;
	struct node* tail;
	int size;
};


struct list* init_list(){
	printf("init list...\n");
	struct list* list = (struct list* ) malloc( sizeof(struct list) );
	if(list == NULL) {
		fprintf(stderr, "Error allocating memory for new list\n");
	}
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;

	return list;
}

void insert(struct list* list, char* key, char* value) {
	struct node* new_node = (struct node* ) malloc( sizeof(struct node) );
	if(new_node == NULL) {
		fprintf(stderr, "Error allocating memory for new node\n");
	}
	new_node->key = key;
	new_node->value = value;
	new_node->next = NULL;
	if(list->head == NULL) {
		list->head = list->tail = new_node;
	} else {
		list->tail->next = new_node;
		list->tail = new_node;
	}

	list->size++;
}


struct list* create_list() {
	printf("creating list...\n");
	struct list* new_list = init_list();
	
	// add each key value pair 
	insert(new_list, "A", "1");
	insert(new_list, "B", "2");
	insert(new_list, "C", "3");
	insert(new_list, "D", "4");
	insert(new_list, "E", "5");
	insert(new_list, "F", "6");
	insert(new_list, "G", "7");
	insert(new_list, "H", "8");
	insert(new_list, "I", "9");
	insert(new_list, "J", "10");
	insert(new_list, "K", "11");
	insert(new_list, "L", "12");
	insert(new_list, "M", "13");
	insert(new_list, "N", "14");
	insert(new_list, "O", "15");
	insert(new_list, "P", "16");
	insert(new_list, "Q", "17");
	insert(new_list, "R", "18");
	insert(new_list, "S", "19");
	insert(new_list, "T", "20");
	insert(new_list, "U", "21");
	insert(new_list, "V", "22");
	insert(new_list, "W", "23");
	insert(new_list, "X", "24");
	insert(new_list, "Y", "25");
	insert(new_list, "Z", "26");

	return new_list;
}

int find_node(struct node* node, char a) {
	while(node != NULL) {
		if(node->key[0] == a) {
			int val = atoi(node->value);
			return val;
		}
		node = node->next;
	}
	return 0;
}

int str_to_int(struct node* head, char* string) {
	int str_len = strlen(string);
	int total = 0;
	char* a;
	for(a = string; *a; a++) {
		//printf("char: %c\n", *a);
		total = total + find_node(head, *a);

	}

	return total;
}

void clean_up(struct list* list) {
	if(list->size > 0){
		struct node* node = list->head;
		struct node* curr;
		while((curr = node) != NULL ) {
			node = node->next;
			free(curr);
		}
	}
	
	free(list);

}

static int compare(const void* a, const void* b) {
	const char **ia = (const char **)a;
    const char **ib = (const char **)b;
    return strncmp(*ia, *ib, 9);
}

/**
 * This code doesn't really work. The answer is close but then the program barfs on itself
 * I wrote this so long ago I'm not really sure how to fix it quickly without devoting a lot 
 * of time to figure out what is wrong.
 */
int main(void) {
	// Based on the description of the problem set this constant
	char* buffer;
	long length;

	FILE* fp = fopen("p022_names.txt", "r");
	if(fp == NULL){
		fprintf(stderr, "Error opening file.\n");
		exit(2);
	}

	fseek (fp, 0, SEEK_END);
	length = ftell (fp);
    fseek (fp, 0, SEEK_SET);
    //buffer = (char*)malloc(length * sizeof(char));
    //memset(buffer, 0, length);
    buffer = (char*)calloc(length, sizeof(char));

  	if (buffer){
  		size_t result = fread (buffer, 1, length-1, fp);
  		buffer[result > 0 ? result : 0] = '\0';

  	}

	fclose(fp);

	struct list* ll = create_list();
	printf("Size of list: %d\n", ll->size);

	// if(ll->size > 0) {
	// 	struct node* current = ll->head;
	// 	while(current->next != NULL) {
	// 		printf("Key: %s, value: %s\n", current->key, current->value);
	// 		current = current->next;
	// 	}
	// 	printf("Key: %s, value: %s\n", current->key, current->value);	
	// }

	//int* array = malloc( sizeof(int) * ll->size);
	char** string_array = malloc( sizeof(char* ) * 5000);
	//char* string_array[5162];

	
	int i = 0;
	if(buffer) {
		char* pch;
		pch = strtok(buffer, ",");
		while(pch != NULL) {
			char* str = remove_quotes(pch);
			string_array[i] = (char* )malloc(1 + sizeof(char*));
			string_array[i] = str;
			//strcpy(str,string_array[i]);
			if(pch == NULL) {
				break;
			}
			pch = strtok(NULL, ",");
			i++;
			if(i==11) {
				//break;
			}
		}
	}

	size_t strings_len = (size_t)i;
	printf("array len: %d, count: %d, sizeof(char*): %d\n", (int)strings_len, i, (int)sizeof(char*));

	for(size_t a = 0; a < strings_len; a++){
		//printf("before %d str: %s\n", (int)a, string_array[a]);
	}

	
	qsort(string_array, strings_len, sizeof(char*), compare);

	long long sum = 0;
	for(size_t a = 0; a < strings_len; a++){
		char* str = string_array[a];
		printf("after %d str: %s\n", (int)a, str);
		int str_val = str_to_int(ll->head,str);
		int total = (a + 1) * str_val;
		//printf("Index value = %d, str val = %d, total = %d\n", (int)a+1, str_val, total);
		sum = sum + (long long)total;

	}

	printf("Sum: %lld\n", sum);

	// for(int x =0; x < i; i++) {
	// 	//free(string_array[i]);
	// }
	
	/* Clean up */
	free(buffer);
	//free(array);
	//free(array);
	//free(string_array);
	clean_up(ll);
	return 0;
}


