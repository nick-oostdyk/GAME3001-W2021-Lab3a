#include "PlayScene.h"
#include "Game.h"
#include "EventManager.h"

// required for IMGUI
#include "imgui.h"
#include "imgui_sdl.h"
#include "Renderer.h"
#include "Util.h"

PlayScene::PlayScene() {
	PlayScene::start();
}

PlayScene::~PlayScene()
= default;

void PlayScene::draw() {

	if (EventManager::Instance().isIMGUIActive()) {
		GUI_Function();
	}

	drawDisplayList();

	SDL_SetRenderDrawColor(Renderer::Instance()->getRenderer(), 255, 255, 255, 255);
}

void PlayScene::update() {

	updateDisplayList();
}

void PlayScene::clean() {

	removeAllChildren();
}

void PlayScene::handleEvents() {

	EventManager::Instance().update();

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_ESCAPE)) {
		TheGame::Instance()->quit();
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_1)) {
		TheGame::Instance()->changeSceneState(START_SCENE);
	}

	if (EventManager::Instance().isKeyDown(SDL_SCANCODE_2)) {
		TheGame::Instance()->changeSceneState(END_SCENE);
	}
}

void PlayScene::start() {

	// Set GUI Title
	m_guiTitle = "Play Scene";

	m_buildGrid();

	//m_pTile = new Tile();
	//m_pTile->getTransform()->position = glm::vec2(400.0f, 300.0f);
	//addChild(m_pTile);

}

void PlayScene::GUI_Function() const {

	// Always open with a NewFrame
	ImGui::NewFrame();

	// See examples by uncommenting the following - also look at imgui_demo.cpp in the IMGUI filter
	//ImGui::ShowDemoWindow();

	ImGui::Begin("GAME3001 - Lab 3", NULL, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoMove);

	// Toggle Grid
	static bool isGridEnabled = false;
	if (ImGui::Checkbox("Enable Grid", &isGridEnabled)) { 
		for (auto tile : m_pGrid) { 
			tile->setEnabled(isGridEnabled);
		}
	}

	ImGui::SameLine();

	if (ImGui::Button("Start")) {

	}

	ImGui::SameLine();

	if (ImGui::Button("Reset")) {

	}

	ImGui::Separator();

	ImGui::End();

	// Don't Remove this
	ImGui::Render();
	ImGuiSDL::Render(ImGui::GetDrawData());
	ImGui::StyleColorsDark();
}

void PlayScene::m_buildGrid() {

	for (int row = 0; row < Config::ROW_NUM; row++) {
		for (int col = 0; col < Config::COL_NUM; col++) {

			m_pGrid.push_back(new Tile());
			m_pGrid.back()->getTransform()->position = glm::vec2(col * Config::TILE_SIZE, row * Config::TILE_SIZE);
			addChild(m_pGrid.back());
			m_pGrid.back()->setEnabled(false);
		}
	}
}