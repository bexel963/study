// 2의 배수만 출력.
var input = window.prompt("숫자를 입력하세요.");
input = parseInt(input);
var num = 1;
while(true){
    if(num == input){
        break;
    }
    if(num%2 == 0){
        document.write(num + " ");
        ++num;
    }else{
        ++num;
        continue;
    }
}