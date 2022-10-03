package ds4;

public class MiniTree {

    Node root = null;

    class Node {
        Node left;
        Node right;
        int data;
        Node() { }
        Node(int data) {
            left = null;
            right = null;
            this.data = data;
        }
    }

    public void addNode(int data) {
        // 노드가 하나도 없을 때.
        if(this.root == null) {
            this.root = new Node(data);
        } else {
            // 노드가 하나 이상 있을 때.
            Node findNode = root;
            while(true) {
                if(data < findNode.data) {
                    if(findNode.left != null) {
                        findNode = findNode.left;
                    } else {
                        findNode.left = new Node(data);
                        break;
                    }
                } else {
                    if(findNode.right != null) {
                        findNode = findNode.right;
                    } else {
                        findNode.right = new Node(data);
                        break;
                    }
                }
            }
        }
    }
    public Node getNode(int data) {
        if(root != null) {
            Node findNode = root;
            while(findNode != null) {
                if(data == findNode.data) {
                    return findNode;
                } else if(data < findNode.data){
                    findNode = findNode.left;
                } else {
                    findNode = findNode.right;
                }
            }
//            while (true) {
//                if (data == findNode.data) {
//                    return findNode;
//                }
//                if (data < findNode.data) {
//                    if (findNode.left != null) {
//                        findNode = findNode.left;
//                    } else {
//                        break;
//                    }
//                } else {
//                    if (findNode.right != null) {
//                        findNode = findNode.right;
//                    } else {
//                        break;
//                    }
//                }
//            }
            return null;
        } else {
            return null;
        }
    }
    // 코너 case를 먼저 해결하는 것이 복잡도를 낮출 수 있다.
    public boolean removeNode(int data) {

        boolean searched = false;

        Node currParentNode = this.root;
        Node currNode = this.root;

        // 코너 case1: Node가 하나도 없을 때
        if(this.root == null) {
            return false;
        } else {
            // 코너 case2: Node가 단지 하나만 있고, 해당 Node가 삭제할 Node 일 때
            if(this.root.data==data && this.root.left==null && this.root.right==null) {
                this.root = null;
            }
            // 삭제할 Node와 그 Node의 부모 Node 찾기
            while(currNode != null) {
                 if(currNode.data == data) {
                     searched = true;
                     break;
                 } else if(data < currNode.data) {
                     currParentNode = currNode;
                     currNode = currNode.left;
                 } else {
                     currParentNode = currNode;
                     currNode = currNode.right;
                 }
            }
            if(searched == false) {
                return false;
            }
        }
        // 여기까지 실행되면,
        // currNode에는 해당 데이터를 가지고 있는 Node,
        // currParentNode에는 해당 데이터를 가지고 있는 Node의 부모 Node 를 참조되게 된다.

        // Case1: 삭제할 Node가 Leaf Node일 경우.
        if(currNode.left==null && currNode.right==null) {
            if(data < currParentNode.data) {
                currParentNode.left = null;
            } else {
                currParentNode.right = null;
            }
        // Case2: 삭제할 Node가 child Node를 하나 가지고 있는 경우.
        } else if(currNode.left!=null && currNode.right==null){
            // Case2-1: child Node가 왼쪽에 있을 경우.
            if(data < currParentNode.data) {
                currParentNode.left = currNode.left;
            } else {
                currParentNode.right = currNode.left;
            }
        } else if(currNode.left==null && currNode.right!=null) {
            // Case2-2: child Node가 오른쪽에 있을 경우.
            if(data < currParentNode.data) {
                currParentNode.left = currNode.right;
            } else {
                currParentNode.right = currNode.right;
            }
        // Case3: 삭제할 Node가 child Node를 두 개 가지고 있을 경우.
        } else if(currNode.left!=null && currNode.right!=null) {
            // Case3-1: 삭제할 Node가 Parent Node의 왼쪽에 있는 경우.
            if(data < currParentNode.data) {
                Node changeNode = currNode.right;
                Node changeParentNode = currNode.right;
                while(changeNode.left != null) {
                    changeParentNode = changeNode;
                    changeNode = changeNode.left;
                }
                // - 삭제할 Node의 오른쪽 Node들 중에서, 가장 작은 값을 가진 Node를 changeNode로 함.
                // Case3-1-1: 삭제할 Node의 오른쪽 자식 중 가장 작은 값을 가진 Node의 오른쪽에 Child Node가 없는 경우.
                if(changeNode.right == null) {
                    changeParentNode.left = null;
                } else {
                // Case3-1-2: 삭제할 Node의 오른쪽 자식 중 가장 작은 값을 가진 Node의 오른쪽에 Child Node가 있는 경우.
                    changeParentNode.left = changeNode.right;
                }
                currParentNode.left = changeNode;
                // - parentNode의 왼쪽 Child Node 가 현재, chageNode 이고,
                //   chageNode 의 왼쪽/오른쪽 Child Node 를 모두 삭제할 currNode의 기존 왼쪽/ 오른쪽 Node로 변경
                changeNode.right = currNode.right;
                changeNode.left = currNode.left;

                currNode = null;    // 쓸 필욘 없지만 삭제한 것을 명시.
            // Case3-2: 삭제할 Node가 Parent Node의 오른쪽에 있는 경우.
            } else {
                Node changeNode = currNode.right;
                Node changeParentNode = currNode.right;
                while(changeNode.left != null) {
                    changeParentNode = changeNode;
                    changeNode = changeNode.left;
                }
                // Case3-2-1: 삭제할 Node의 오른쪽 자식 중 가장 작은 값을 가진 Node의 오른쪽에 Child Node가 없는 경우.
                if(changeNode.right == null) {
                    changeParentNode.left = null;
                } else {
                // Case3-2-2: 삭제할 Node의 오른쪽 자식 중 가장 작은 값을 가진 Node의 오른쪽에 Child Node가 있는 경우.
                    changeParentNode.left = changeNode.right;
                }
                currParentNode.right = changeNode;
                // - parentNode의 왼쪽 Child Node 가 현재, chageNode 이고,
                //   chageNode 의 왼쪽/오른쪽 Child Node 를 모두 삭제할 currNode의 기존 왼쪽/ 오른쪽 Node로 변경
                changeNode.right = currNode.right;
                changeNode.left = currNode.left;

                currNode = null;    // 쓸 필욘 없지만 삭제한 것을 명시.
            }
        }
        return true;
    }
//    public boolean removeNode(int data) {
//        if(root != null) {
//            Node prevNode = null;
//            Node findNode = root;
//            while(findNode != null) {
//                if(findNode.data == data) {
//                    if(findNode.left==null && findNode.right==null) {
//                        return removeLeafNode(prevNode, findNode);
//                    } else if(findNode.left!=null && findNode.right!=null) {
//                        return removeWidthTwoChildNode(prevNode, findNode);
//                    } else {
//                        return removeWidthOneChildNode(prevNode, findNode);
//                    }
//                } else if(data < findNode.data) {
//                    prevNode = findNode;
//                    findNode = findNode.left;
//                } else {
//                    prevNode = findNode;
//                    findNode = findNode.right;
//                }
//            }
//            return false;
//        } else {
//            return false;
//        }
//    }

    private boolean removeWidthTwoChildNode(Node prevNode, Node findNode) {
        if(prevNode.right.data == findNode.data) {
            findNode = findNode.right;
            while(findNode.left != null) {
                findNode = findNode.left;
            }
            prevNode.right = findNode;
            return true;
        } else if(prevNode.left.data == findNode.data) {
            findNode = findNode.right;
            while(findNode.left != null) {
                findNode = findNode.left;
            }
            prevNode.left = findNode;
            return true;
        }
        return false;
    }

    private boolean removeWidthOneChildNode(Node prevNode, Node findNode) {
        if(findNode.right != null) {
            if(prevNode.right.data == findNode.data) {
                prevNode.right = findNode.right;
                return true;
            } else if(prevNode.left.data == findNode.data) {
                prevNode.left = findNode.right;
                return true;
            }
        } else if(findNode.left != null) {
            if(prevNode.right.data == findNode.data) {
                prevNode.right = findNode.left;
                return true;
            } else if(prevNode.left.data == findNode.data) {
                prevNode.left = findNode.left;
                return true;
            }
        }
        return false;
    }

    private boolean removeLeafNode(Node prevNode, Node findNode) {
        if(prevNode.right.data == findNode.data) {
            prevNode.right = null;
            return true;
        } else if(prevNode.left.data == findNode.data) {
            prevNode.left = null;
            return true;
        }
        return false;
    }

}
