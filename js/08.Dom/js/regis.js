function newRegister() {
    // 새로운 p태그 요소 만들기
    var newP = document.createElement("p");
    var userName = document.querySelector("#userName");

    // 새로운 텍스트 노드를 만든다.
    var text = document.createTextNode(userName.value);

    // p노드가 상위요소가 되고 text라는 하위 요소를 연결한다.
    newP.appendChild(text);

    // 새로운 버튼 노드를 추가
    var delBtn = document.createElement("span");
    // 새로운 텍스트 노드 추가
    var delText = document.createTextNode("X");
    // x 버튼에 class선택자 속성을 추가
    delBtn.setAttribute("class", "del");
    // 텍스트 노드를 button의 자식 요소로 연결.
    delBtn.appendChild(delText);
    newP.appendChild(delBtn);

    var nameList = document.querySelector("#nameList");
    
    // p요소를 #nameList의 맨 앞에 추가
    nameList.insertBefore(newP, nameList.childNodes[0]);
    // p노드가 #nameList의 하위요소가 된다.
    // nameList.appendChild(newP);

    // input 필드 지우기
    userName.value = "";

    var removeBtns = document.querySelectorAll(".del");

    for(var i=0; i<removeBtns.length ; i++) {
        removeBtns[i].addEventListener("click", function(){
            // #nameList를 의미함. (span태그의 부모가 p이고, p의 부모가 #nameList이기 때문이다.)
            if(this.parentNode.parentNode) {
                // p태그를 삭제함.
                this.parentNode.parentNode.removeChild(this.parentNode);
            }
        });
    }
}