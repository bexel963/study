// 변수 heading에 id가 heading인 태그의 정보를 저장
var heading = document.querySelector("#heading");
// 변수를 클릭하면 함수 실행
heading.onclick = function() {
    heading.style.color = "red";
}