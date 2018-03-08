#include <stdio.h>
#include <string.h>

struct Person{
	char fullName[40];
	float heigt;
};

Person enterData(){
	Person p;
	printf("Nhap ho ten: "); fflush(stdin); gets(p.fullName);
	printf("Nhap chieu cao: ");  scanf("%f", &p.heigt);
	return p;
}

void inputData(Person *data, int & count) {
	Person p = enterData();
	data[count] = p;
	count++;
}
void insertData(Person *data, int & count) {
	int pos = 0;
	printf("Nhap vi tri chen du lieu : "); scanf("%d", &pos);
	Person p = enterData();
	for(int i = count ; i > pos; i--) { 
		data[i] = data[i - 1];
	}
	data[pos] = p;
	count++;
}

void toString(Person p) {
	printf("FullName:%s\nHeight:\t%2f\nWeight:\t%d\n-----------------------------\n",p.fullName, p.heigt,(int) (p.heigt *100 - 110));
}

void showListData(Person * data, int count) {
	for(int i = 0; i < count; i++) {
		toString(data[i]);
	}
}

int find(Person * data, int count , char * name) {
	for(int i = 0; i < count; i++) {
		if(strcmp(name, data[i].fullName) == 0){
			 return i;		 
		}
	}
	return -1;
}

void findPersonByName(Person * data, int count) {
	char name[40];
	printf("Nhap ten can tim: "); fflush(stdin); gets(name);
	int pos = (int) find(data, count, name);
	if(pos > -1) {
		toString(data[pos]);
	} else {
		printf("Khong tim thay \n-----------------------------\n");
	}
}
int findByName(Person * data, int count) {
	char name[40];
	printf("Nhap ten can tim: "); fflush(stdin); gets(name);
	return (int) find(data, count, name);
}


void deletePersonByPosition(Person * data, int & count) {
	int pos = -1;
	printf("\nTHIS IS FUNCTION DELETE PERSON BY POSITION\n");
	printf("NHAP VI TRI CAN XOA: "); scanf("%d", &pos);
	count = count - 1;
	for(int i = pos; i < count; i++) {
		data[i] =  data[i + 1];
	}
}
void deletePersonByPosition(Person * data, int & count, int pos) {
	count = count - 1;
	for(int i = pos; i < count; i++) {
		data[i] =  data[i + 1];
	}
}

void deletePersonByName(Person * data, int count) {
	int pos = findByName(data, count);
	if(pos > -1) {
		deletePersonByPosition(data, count, pos);
	} else {
		printf("Khong tim thay \n-----------------------------\n");
	}
}

int main() {
	Person ds[100];
	int count = 0, pos = -1;
	
	
	printf("Muc luc: \n");
	printf("1.Liet ke cac phan tu trong mang \n");
	printf("2.Tim phan tu theo ho ten, in ra phan tu dau tien co ho ten do \n");
	printf("3.Nhap phan tu , vi tri can them vao danh sach \n");
	printf("4.Nhap vi tri can xoa \n");
	printf("5.Xoa phan tu theo ho ten \n");
	printf(" ----------------------------------------\n ");
	printf("Nhap muc can thuc hien: "); scanf("%d", &pos);
	
	switch(pos) {
		case 1: {
			showListData(ds, count);
			break;
		};
		case 2:{
			findPersonByName(ds, count);
			break;
		}
		case 3: {
			insertData(ds, count);
			break;
		}
		case 4: {
			deletePersonByPosition(ds, count);
			break;
		}
		case 5:{
			deletePersonByName(ds, count);
			break;
		}
		default: {
			printf("\nKHONG CO MUC BAN CHON >.<\n=====================================\n");
			break;
		}
	}
}
