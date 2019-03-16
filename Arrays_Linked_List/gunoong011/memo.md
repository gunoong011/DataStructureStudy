# 1. Arrays

* Using java.util.Arrays, 자바 배열 함수 이용

## 1.1. Copying array

System.arraycopy(source array, 시작 인덱스 ,목적 어레이, 목적어레이에서 복사를 시작할 인덱스, 복사할 원소갯수)

* page 12, 13



## 1.2. Array를 비교할 때 

### size 비교 

### 원소 하나씩 비교

`Arrays.equals(arr1,arr2)`



## 1.3. Array filling(배열에 있는 모든 원소들을 원하는 값으로 세팅할 때)

###(1) for 문을 돌려 원소에 채워넣는다.

###(2) 함수 이용 

`Arrays.fill(array, value);`

`Arrays.fill(array,fromindex,toindex,value);`



## 1.4. 배열에 들어있는 값을 확인을 할려면 

###(1) 반복문 

for, while loop등을 이용하여 확인하는 일반적인 방법

그리고 각각의 인덱스를 이용하여 출력한다.

###(2) 함수 이용 

`Arrays.toString(array)`

배열에 있는 원소들을 print 해준다(굳이 for loop를 돌리지 않아도 된다)



## 1.5. 배열 sort

java.util.Arrays 클래스 내의 메소드인 sort를 이용한다.

`Arrays.sort(array)` 

참고로 two pivoting quick sort를 이용한다.



## 1.6. 배열 원소 복사 

배열에 있는 값을 가지고 새로운 배열을 만들어준다

type[] arr2 = Arrays.copyOf(복사할 arr1, 생성할 배열의 사이즈)
-> 생성하는 배열의 원소가 클 경우 복사하고 남은 인덱스의 원소는 0을 채워준다

type[] arr2 = Arrays.copyOf(복사할 arr1, fromindex,toindex)
-> arr1에서 fromindex ~ toindex-1 까지의 원소를 복사해준다



## 1.7. 함수의 원소 합 구하기 

### (1) 반복문 이용

for, while loop 등을 이용하여 모든 원소를 합한다.

### (2) stream 이용

array -> stream 으로 바꾸고 더하기

int total = Arrays.stream(array).sum()


--------------------------------------------------------------------------------


# 2. Singly Linked List

## Array와의 차이점

연속적인 메모리 공간을 차지 하지 않는다

Array는 원소들이 메모리 상에서 연속적으로 배치되어 있다.


## 2.1. Node class (page3)

### 2.1.1. node(linkedlist의 구성요소) class에 들어갈 것들

#### (1) element

- 원소들의 타입이 규정이 되어야하나??
- 굳이 그럴 필요 없다 -> generics 이용 -> 임의의 타입 지정 가능

#### (2) 나 다음에 있는 것이 어디 있는 지를 알려주어야한다
-> link to the next node

### 2.1.2. Self-Reference Class 

#### (1) Node<E> class

next element type : Node<E>가 되어야한다

#### (2) 자기 자신을 다시 참조하는 것 

```java
public class Node<E>{
	private E element ; 
	private Node<E> next ;
	/* 다음 원소를 가리킬 것이 필요하다*/
}
```

####(3) constructor 

```java
public Node(){
	this(null, null);
	/* parameter가 2개인 생성자를 호출한 것이다 */
}

/* 위에 있는 것은 default-constructor, 
만들어주는 것이 필요하다(가장 기본적인 생성자)
아무 것도 만들지 않을 수가 있으므로
*/

public Node(E e, Node<E> n){
	element = e ; 
	next = n ;
}
```

### 2.1.3. Node class 함수 설명 

* setElement : element 새로 설정
* setNext : next 새로 설정



## 2.2. Implementation of SLL(page 8)

### (1) 처음 원소(head)와, 마지막 원소(tail)를 설정해준다

```java
protected Node<E> head ;
protected Node<E> tail ;
protected long size ;
```

###(2) default constructor : 링크드 리스트가 처음 만들었을 때를 가리킨다 

링크드 리스트가 처음 만들어졌으므로 따라서 노드가 아무것도 없다

```java
head = null, tail = null
```



## 2.3. Link Traversal(page 9)

### (1) printAll()

- cursor라는 것을 만들어 현재 노드의 위치를 가리켜주는 것이다
- cursor가 null이 아닐 때까지 움직여서 모든 원소를 출력을 한다



## 2.4. Insertion at the Head(page 10)

새로운 헤드 만들기 (순서가 중요하다 /3,4번의 순서가 특히 중요하다)

**순서**

(1) 새로운 노드 할당 
(2) 만든 노드에 넣고 싶은 원소 할당 
(3) 새로운 헤드가 올드 헤드를 가리키게 한다 (다음원소를 올드 헤드로 지정)
(4) 헤드를 새로운 헤드를 가리키게 한다 
(5) 사이즈를 하나 늘린다

// 구현 12페이지


## 2.5. Insertion at the tail(page 13)

**순서**

(1) 새로운 노드 생성 후 새로운 노드에 원소 새로 넣기

(2) 새로운 노드의 다음 노드는 null 

(3) 원래 테일의 다음 노드를 새로운 노드를 가리키게 한다 

(4) 테일이 새로운 노드를 가리키게한다(테일이라는 것을 따로 설정을 해놓았으므로)

(5) 사이즈 증가

// 구현 14페이지



## 2.6. Removing at the Head (페이지 15)

**순서**

(1) head = head.getNext();

(2) Garbage collector가 쓰지않는 헤드를 회수해가게 시킨다.

(3) 사이즈 하나 줄이기


##2.7. Tail 노드 제거하기 (페이지 17)

**SLL의 단점이 드러나게 되는 시점**

테일의 전 노드에 접근하기가 어려움 

따라서 헤드에서 부터 차례대로 접근을 해야한다

--------------------------------------------------------------------------------


# 3. Doubly Linked List (18)

SLL에서의 단점을 보완한 것 (바로 전 노드를 찾기 위해 만듦)

## 3.1. DLL에서 Node class

(1) prev, element, next 

- 바로 전 노드를 가리키는 것을 추가한 것이다

(2) getPrev, setPrev 등 함수 추가 필요

private로 구현할 것이기 때문이다

## 3.2. Double Linke List

### (1) header, trailer에 대한 설명

header == head
trailer == tail

### (2) Empty list (19)

header, trailer가 서로를 가리키게 하면된다

### (3) constructor(22)

**순서**

1. header가 trailer보다 먼저 만들어졌으므로 `header = new Node<E>(null,null,null);` 가 됨 

2. header가 만들어졌으므로 trailer는 header를 가리켜줄 수 있음 `trailer = new Node<E>(null,header,null)`이 됨

3. 마지막으로 header가 trailer를 가리키게한다. `header.setNext(trailer)`


## 3.3. DLL Implementation

### (1) 특정 노드를 어떤 노드 앞에 저장하기(24)

순서가 중요하다. 갑자가 노드가 날라갈 수 있다.

### (2) 특정 노드를 어떤 노드 뒤에 저장하기(25)

순서가 중요하다. 갑자가 노드가 날라갈 수 있다.

### (3) Front, Tail에 새로운 원소넣기

### (4) remove a node (27)

사이즈를 잘 줄이자 (하니씩 줄이자)

null을 넣어주는 것이 좋다

## 3.4. circular linked list

마지막 노드의 next가 처음 노드를 가리키는 것이다...

추가로 하나의 노드를 더해서 circular linked list 를 구현할 수 있다
(추가 보충 필요)