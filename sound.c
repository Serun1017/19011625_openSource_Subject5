#include "Sound.h"
float volume = 0.5;
float monVol;
IsPlaying = FALSE;

void SoundInit(void) {
	soundPos.X = 0;
	soundPos.Y = 0;

	FMOD_System_Create(&g_System);
	FMOD_System_Init(g_System, 15, FMOD_INIT_NORMAL, NULL); //�ִ� 10���� �Ҹ��������

	//���� ���� -�ּ� ó���� �׸���� �߰��� ����
	FMOD_System_CreateSound(g_System, "sound/walking.wav", FMOD_DEFAULT, 0, &g_Sound[0]);

	FMOD_System_CreateSound(g_System, "sound/getItem1.wav", FMOD_DEFAULT, 0, &g_Sound[1]);
	//FMOD_System_CreateSound(g_System, "sound/getItem2.wav", FMOD_DEFAULT, 0, &g_Sound[2]);
	FMOD_System_CreateSound(g_System, "sound/getGun.wav", FMOD_DEFAULT, 0, &g_Sound[3]);
	FMOD_System_CreateSound(g_System, "sound/getKey.mp3", FMOD_DEFAULT, 0, &g_Sound[4]);

	FMOD_System_CreateSound(g_System, "sound/monster.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[5]);
	FMOD_System_CreateSound(g_System, "sound/useItem1.wav", FMOD_DEFAULT, 0, &g_Sound[6]);
	//FMOD_System_CreateSound(g_System, "sound/useItem2.mp3", FMOD_DEFAULT, 0, &g_Sound[7]);
	//FMOD_System_CreateSound(g_System, "sound/useGun1.wav", FMOD_DEFAULT, 0, &g_Sound[8]);
	FMOD_System_CreateSound(g_System, "sound/useGun2.wav", FMOD_DEFAULT, 0, &g_Sound[9]);
	FMOD_System_CreateSound(g_System, "sound/useKey.mp3", FMOD_DEFAULT, 0, &g_Sound[10]);

	FMOD_System_CreateSound(g_System, "sound/damage.mp3", FMOD_DEFAULT, 0, &g_Sound[11]);
	FMOD_System_CreateSound(g_System, "sound/gameover.mp3", FMOD_DEFAULT, 0, &g_Sound[12]);
	FMOD_System_CreateSound(g_System, "sound/main.mp3", FMOD_LOOP_NORMAL, 0, &g_Sound[13]);
	FMOD_System_CreateSound(g_System, "sound/selectUI.wav", FMOD_DEFAULT, 0, &g_Sound[14]);
}

void StopSound(int n) {
	FMOD_Channel_Stop(channel[n]);
}

void VolumeSetSound(int n) {
	FMOD_Channel_SetVolume(channel[n], volume);
}

void SoundUpdate(void) {
	if (IsPlaying == 1) {
		FMOD_System_Update(g_System);
	}
}

void VolumeCtrl(void) {

}

void Sound_Play(int n) {
	FMOD_System_PlaySound(g_System, g_Sound[n], 0, 0, &channel[n]);
	//�÷��̾ �Ȱų� ���� ����ϴ� ��쿣 �÷��̾��� ��ġ�� �Ҹ��� �� �������� ����
	if (n == USE_GUN2) {
		soundPos = player.playerPos;
	}
	// ������ �������� ����ϴ� ��� �����̰� ���� �ε����� ������ �Ҹ��� �� �������� ����
	else if (n == USE_ITEM1) {
		soundPos = rock.arriveRockPos;
	}
}
void FindMonster(int mx, int my) {
	int px, py;
	int distance;
	px = player.playerPos.X / 2;
	py = player.playerPos.Y;
	distance = (px - mx) * (px - mx) + (py - my) * (py - my);
	if (distance < 20) {
		monVol = 0.5;
		FMOD_Channel_SetVolume(channel[MONSTER], 0.5);
	}
	else if (distance < 40) {
		monVol = 0.3;
		FMOD_Channel_SetVolume(channel[MONSTER], 0.3);
	}
	else if (distance < 70) {
		monVol = 0.1;
		FMOD_Channel_SetVolume(channel[MONSTER], 0.1);
	}
	if (distance < 70) {
		if (IsPlaying == FALSE) {
			Sound_Play(MONSTER);
			FMOD_Channel_SetVolume(channel[MONSTER], monVol);
			IsPlaying = TRUE;
		}
	}
	else {
		StopSound(MONSTER);
		IsPlaying = FALSE;
	}
}
COORD SoundPoint() {
	return soundPos;
}