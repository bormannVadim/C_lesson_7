// Lesson_7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
/*
  Savenko V 
  Lesson 7 
  Run Lee
 */
#include <stdio.h>
#include <stdlib.h>
//
//typedef struct GraphNode {
//	int data;
//	int index;
//	int used;
//	struct List* children;
//} GraphNode;
//
//int widthTravers(GraphNode *start, GraphNode * stop) {
//	pushQueue(q, start);
//	start->used = 1;
//	while (q->size != 0) {
//		GraphNode current = popQueue(q);
//		if (current->data == stop->data)
//			return 1;
//
//		while (current->children.size != 0) {
//			int i;
//			for (i = 0; i < children.size; i++) {
//				if (children.get(i).used != 1) {
//					pushQueue(q, children.get(i));
//					children.get(i).used = 1;
//				}
//			}
//		}
//	}
//}

const int w = 11;
const int h = 12;
const int OBSTACLE = -1;
const int UNVISITED = -2;
int grid[h][w];
int len;
int pointX[h * w];
int pointY[h * w];
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
//init grid with -2 here))

int lee(int sx, int sy, int ex, int ey) {

	int x, y, vector, dist, stop;
	if (sx == ex && sy == ey) return 0;

	//UNVISITED
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++)
			grid[j][h] = UNVISITED;

	// 11x12 
	//OBSTACLE
	for (int j = 6; j < 8; j++)// RANDOM NUMBERS
		grid[4][j] = OBSTACLE;


	if (grid[sy][sx] == OBSTACLE || grid[ey][ex] == OBSTACLE) return 0;
	//sx , sy -begining ;  ex,ey-ending

	dist = 0;// step
	grid[sy][sx] = dist;// begining point

	do {
		stop = 1;
		for (y = 0; y < h; y++) {
			for (x = 0; x < w; x++) {
				if (grid[y][x] == dist) {
					for (vector = 0; vector < 4; vector++) {
						int nextX = x + dx[vector];
						int nextY = y + dy[vector];
						if (nextX >= 0 && nextX < w &&
							nextY >= 0 && nextY < h &&
							grid[nextY][nextX] == UNVISITED) {
							stop = 0;
							grid[nextY][nextX] == dist + 1;
						}
					}
				}
			}
		}
		dist++;
	} while (!stop && grid[ey][ex] == UNVISITED);

	if (grid[ey][ex] == UNVISITED) return 0;

	len = grid[ey][ex];
	x = ex;
	y = ey;
	while (dist > 0) {
		pointX[dist] = x;
		pointY[dist] = y;
		dist--;
		for (vector = 0; vector < 4; vector++) {
			int nextX = x + dx[vector];
			int nextY = y + dy[vector];
			if (nextX >= 0 && nextX < w &&
				nextY >= 0 && nextY < h &&
				grid[nextY][nextX] == dist) {
				x = nextX;
				y = nextY;
			}
		}
	}
	return 1;
}

int main(int argc, const char** argv) {

	printf("%d",lee(3, 5, 10, 4));
	
	return 0;
}