Đề bài
Cho một ma trận m * n miêu tả phân bổ chỗ ngồi trong phòng họp. Nếu như một chỗ không thể ngồi được thì sẽ được miêu tả bằng số 0, ngược lại thì được mô tả bằng số 1.

Một nhân viên của công ty F có thể nhìn được máy tính của người ngồi ở vị trí bên trái, bên phải, phía trên bên phải hoặc phía trên bên trái của họ. Nhưng người đó không thể nhìn thấy máy tính của người ngồi phía trước hoặc phía sau của mình. Chị N. phụ trách bảo mật của công ty muốn tổ chức một buổi kiểm tra thật nghiêm túc về quy trình bảo mật của công ty. Hỏi chị N. có thể cho phép tối đa bao nhiêu nhân viên tham gia buổi kiểm tra mà không xảy ra trường hợp nhìn bài nhau.




Đầu vào
Một ma trận m * n
Đầu ra
Một số nguyên thể hiện số nhân viên tối đa có thể tham gia test

Ràng buộc
Ma trận chỉ bao gồm 2 chữ số 0 và 1
1 <= m <= 10
1 <= n <= 10

Yêu cầu:
Mã nguồn phải có phần đọc input từ file: input.txt
Output được ghi vào file output.txt

Ví dụ:
Input:
0 1 0 0 1 0
1 0 0 0 0 1
0 1 0 0 1 0
Output: 4
Giải thích: N. có thể cho phép 4 nhân viên vào tham gia làm bài test

Input:
0 1 1 1 0
1 0 1 0 1
1 1 0 1 1
1 0 1 0 1
0 1 1 1 0
Output: 10
Giải thích: N có thể cho các nhân viên vào ngồi ở vị trí cột 1, 3, 5


 
