#include "CameraController.h"
#include "Tobes/Common/Input.h"
#include "Tobes/Common/Component.h"
#include "Tobes/Common/Components/Transform.h"


void CameraController::Update(float dt)
{
	Tobes::Input* input = Tobes::Input::GetInstance();

	if (input->IsKeyDown(KeyCode_W))
		transform->Translate(transform->GetForward() * dt * 5);
	if (input->IsKeyDown(KeyCode_S))
		transform->Translate(transform->GetForward() * -dt * 5);
	if (input->IsKeyDown(KeyCode_A))
		transform->Translate(transform->GetRight() * -dt * 5);
	if (input->IsKeyDown(KeyCode_D))
		transform->Translate(transform->GetRight() * dt * 5);

	if (input->GetMouseDeltaX() != 0)
		transform->Rotate(Vector3(0, 1, 0), input->GetMouseDeltaX() * -dt * 0.1f);
	if (input->GetMouseDeltaY() != 0)
		transform->Rotate(transform->GetRight(), input->GetMouseDeltaY() * -dt * 0.1f);
}
