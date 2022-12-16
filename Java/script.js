var count;
var temp;
let arr = new Array(20);
var kol = 0;

//document.write("<pre>Выполнение 5-ой лабораторной \n<\/pre>");
//m1 = prompt('Введите первое число: ');
//document.write("Первое число: ", m1);

kol = prompt('Введите кол-во элементов: ')

for (var i = 0; i<kol; i++){
		arr[i] = prompt('Введите элемент');
}

for (var i = 0; i < kol;){
		if (arr[i] < arr[i+1])
		{
			document.write(arr[i]);
			i=i+2;
		}
		else
			document.write(arr[i+1]);
			i= i+2;
}