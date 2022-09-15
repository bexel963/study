// 윈도우가 열릴 때
window.onload = function(){
    var list = "";
    var num = 10;

    // 복합 대입 연산자를 통하여 list변수에 문자열을 누적하고 있다.
    list += "<ul>";
    list += "   <li>안녕</li>";
    list += "   <li>자바스크립트</li>";
    list += "</ul>";
    
    // 문서에 출력
    document.body.innerHTML = list;

    num += 10;  num += 10;
    num += 10;  num += 10;

    //document.body.innerHTML = num;
}