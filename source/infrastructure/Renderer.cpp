#include "Renderer.h"

Renderer::Renderer(std::shared_ptr<Board> board)
: board(std::move(board))
{}

