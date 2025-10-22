int evaluatePostfix(string expr, Stack& stack) {
    for (char ch : expr) {
        if (isdigit(ch)) {
            stack.push(ch - '0');
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int b = stack.pop();
            int a = stack.pop();
            if (a == -999 || b == -999) return -999;

            switch (ch) {
                case '+': stack.push(a + b); break;
                case '-': stack.push(a - b); break;
                case '*': stack.push(a * b); break;
                case '/': stack.push(b != 0 ? a / b : -999); break;
            }
        } else {
            return -999; // invalid character
        }
    }
    return stack.pop();
}
