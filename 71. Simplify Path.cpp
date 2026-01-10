class Solution {
    public String simplifyPath(String path) {
        String[] split = path.split("/+");
        Stack<String> stack = new Stack<>();

        for (String str : split) {
            if (str.equals(".")) continue;
            if (str.equals("..")) {
                if (!stack.empty()) stack.pop();
            }
            else stack.push(str);
        }

        String simplifiedPath = "";

        while (!stack.empty()) {
            String next = stack.peek();
            stack.pop();
            if (simplifiedPath.equals("")) simplifiedPath = next;
            else simplifiedPath = next + "/" + simplifiedPath;
        }

        if (simplifiedPath.length() == 0 || simplifiedPath.charAt(0) != '/') simplifiedPath = "/" + simplifiedPath;

        return simplifiedPath;
    }
}
