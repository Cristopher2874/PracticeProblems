def isValid(s: str) -> bool:
    stack = []
    openChar = {
        ")":"(",
        "]":"[",
        "}":"{"
        }
    for character in s:
        if character in openChar.values():
            stack.append(character)
        else:
            if character in openChar and len(stack) > 0 and stack[-1] == openChar[character]:
                stack.pop()
            else:
                return False
    return len(stack) == 0

print(isValid("()()]"))            