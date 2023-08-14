# Tic-Toc-Toe


Update :
- cài thêm chế độ bot  
- cài thêm nhạc  
- cải tiến bot : ban đầu là để bot random vị trí trống, nhưng bot sẽ rất khó thắng, dùng if else để bot dễ dàng thắng hơn và khi đánh với bot sẽ không win được vì thuật toán sẽ giúp bot đánh hòa  
- có thử qua minimax  


Cải tiến trong tương lai :
- thêm phần chọn lượt đánh bằng 1 hình thức ngẫu nhiên : như tung đồng xu, mỗi người chọn 1 mặt ( người chơi chọn mặt khi chơi với bot )
- cải tiến lên 5x5
- thêm 1 số chế độ như giới hạn thời gian khi nxn (n > 9 ), hay 1 hình thức trả lời câu hỏi để được đánh liên tục  

Classes :  

1. 
First class Graphic: lưu biến Renderer,Window
	+)method : renderTexture Vẽ ảnh vào vị trí mong muốn trên màn hình 
	biến texture để lưu ảnh cần đưa,rect lưu vị trí
2.
Second class Texture : lưu biến texture và thông số chiều cao,dài.
	+)method : render import 1 texture với thông số về chiều cao và dài
3.
Third class GameState: là 1 abstract class được sử dụng để đại diện cho các khái niệm chung :       
     Intro, Title Screen,Game play,Game over,exit.
	+)biến nextStateID : chứa các state ta muốn dùng
	+)các method -)virtual handleEvents(SDL_Event &e) cử lý sự kiện
		     -)virtual logic ,render(Graphic &graphic)
4.
Fourth class Intro kế thừa GameState: hiện intro cho game
+)biến Texture introImage chứa image intro .
+)method Intro(Graphic &graphics) để load intro
+)method handleEvents(SDL_Event &e) chức năng cơ bản: nếu ấn exit sẽ thoát chương trình ấn Enter để tiếp tục game or chờ 5s
5.
Fifth class title tương tự intro
6.
Sixth class Button: lưu trữ vị trí  chiều cao,dài,biến currentSpriteID lưu sprite cần sử dụng để render ,Position lưu vị trí của button
7.
Seventh class Board :
	+) struct PositionCoordinate chứa biến positionID là thứ tự của board trong bảng và pair<> coordinate lưu tọa độ , biến gameBoard[9] tương ứng với 9 ô
	+)class board chứ tên ô và vị trí
	+)method allEqual kiểm tra xem 3 ô có cùng ký tự X or O ko
	+) method rowWin trả về true nếu 3 ô liên tiếp trên cùng 1 hàng có cùng ký tự sử dụng method Equal
	+) method columnWin ,leftDiagonalWin,rightDianogalWin tương tự
	+) method boardisFull sẽ trả về kết quả hòa
	+)method isValidMove(int move) cho biết ô nào còn trống
8.
Eighth class GameOver biến Texture gameoverScreen lưu ảnh gameOver các handle event tương tự
9.
Nineth class Game: biến Graphics graphics,GameState* currentState,int currentStateID,int nextState
	+)Method gameLoop gán currentSt
10.
Tenth class Mixer : Loading music
11.
ELeventh class Play : - Chứa thuật toán, các event khi 2 người chơi trên bàn cờ
12.
Last class Playbot : - Tương tự class 11, nhưng là người chơi với bot 
		     - Sử dụng biến random, minmax(chưa hoàn thiện), if-else
		
