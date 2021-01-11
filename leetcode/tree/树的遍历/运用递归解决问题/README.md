# 运用递归解决问题
递归是解决树相关问题的一种常用方法，我们知道树可以使用递归方式定义为一个节点，他包括一个值及一个指向其他节点的列表,递归是树的特性之一，因此许多树问题可以使用递归的方法来解决，对于每个层级我们之需要关注单个节点内的问题，并通常通过调用递归函数来解决此类问题

## 自顶向下的解决方案
自顶向下意味着在每个递归层级，我们首先访问节点来计算某些值，并在递归调用时将这些值传递到子节点，所以自顶向下的解决方案可以被认为是一种**前顺遍历**,具体来说递归函数的原理是这样的.
```
return specific value for null node(返回节点为空的特定值)
update the answer if needed(根据需要更新答案)
left_ans = top_down(root.left, left_params)
right_ans = top_down(root.right, right_params)
return the answer if needed(根据需要返回答案)
```

例如: 给定一个二叉树，寻找他的最大深度
```
int answer;		       // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}
```


## 自底向上的解决方案
“自底向上” 是另一种递归方法。 在每个递归层次上，我们首先对所有子节点递归地调用函数，然后根据返回值和根节点本身的值得到答案。 这个过程可以看作是**后序遍历**的一种.
```
return specific value for null node(返回节点为空的特殊值)
left_ans = bottom_up(root.left)
right_ans = bottom_up(root.right)
return answers
```
例如:给定一个二叉树，求最大深度
```
int maximum_depth(TreeNode* root) {
	if (!root) {
		return 0;                                 // return 0 for null node
	}
	int left_depth = maximum_depth(root->left);
	int right_depth = maximum_depth(root->right);
	return max(left_depth, right_depth) + 1;	  // return depth of the subtree rooted at root
}
```

## 总结
了解递归并利用递归解决问题并不容易。
当遇到树问题时，请先思考一下两个问题：

你能确定一些参数，从该节点自身解决出发寻找答案吗？
你可以使用这些参数和节点本身的值来决定什么应该是传递给它子节点的参数吗？
如果答案都是肯定的，那么请尝试使用 “自顶向下” 的递归来解决此问题。

或者你可以这样思考：对于树中的任意一个节点，如果你知道它子节点的答案，你能计算出该节点的答案吗？ 如果答案是肯定的，那么 “自底向上” 的递归可能是一个不错的解决方法
