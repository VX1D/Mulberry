# Not done: functions still using inline asm

118 functions in 42 files match the original but still contain inline `__asm__`
(directly or via inline VU0 helpers). They count as matched, not as done.
`.word` = raw instruction bytes in the asm.

## src/cs4/Seimei/fslib/lib/fslibvu0.c

- [ ] `fsvu0_AddVector`
- [ ] `fsvu0_ApplyMatrix`
- [ ] `fsvu0_CopyVectorF`
- [ ] `fsvu0_MulMatrix`
- [ ] `fsvu0_Normalize`
- [ ] `fsvu0_OuterProduct`
- [ ] `fsvu0_ScaleVector`
- [ ] `fsvu0_SubVector`

## src/cs4/Seimei/fslib/lib/hit_calc.c

- [ ] `OuterProduct`

## src/cs4/Seimei/src/Anim.c

- [ ] `CheckAnimParam` — `.word`
- [ ] `GetAnimSclFrameData` — `.word`

## src/cs4/Seimei/src/Camera.c

- [ ] `SetCamAmbient`
- [ ] `SetCamEnv`
- [ ] `SetCamPathDirect`

## src/cs4/Seimei/src/CharHit.c

- [ ] `CheckHitChar` — `.word`

## src/cs4/Seimei/src/Drama.c

- [ ] `FreeDramaData` — `.word`

## src/cs4/Seimei/src/Draw.c

- [ ] `CheckDramaDrawModel`

## src/cs4/Seimei/src/DrawOT.c

- [ ] `DrawByOT`

## src/cs4/Seimei/src/E022Act.c

- [ ] `E022ActDamage`
- [ ] `SetE022Jump`

## src/cs4/Seimei/src/E033Act.c

- [ ] `SetE033Dead`

## src/cs4/Seimei/src/E034Act.c

- [ ] `E034ActAttack`

## src/cs4/Seimei/src/E035Act.c

- [ ] `SetE035Dead`

## src/cs4/Seimei/src/E041Act.c

- [ ] `SetE041Dead`

## src/cs4/Seimei/src/E044Act.c

- [ ] `SetE044Dead`

## src/cs4/Seimei/src/Ene.c

- [ ] `EneSetTarget`

## src/cs4/Seimei/src/EneAct.c

- [ ] `SetEneClingOut`
- [ ] `SetEneDamage`
- [ ] `SetEneDead`
- [ ] `SetEneFree`
- [ ] `SetEneGuard`

## src/cs4/Seimei/src/EneDamage.c

- [ ] `EneLifeCutProc`
- [ ] `SetChainDamage`

## src/cs4/Seimei/src/Event0006.c

- [ ] `PlayS0006Event001`

## src/cs4/Seimei/src/Event0085.c

- [ ] `InitS0085Event000`

## src/cs4/Seimei/src/FrontEnd/FrontEnd_Card.c

- [ ] `_CardFuncs_Act_Blood` — `.word`

## src/cs4/Seimei/src/ItemMng.c

- [ ] `ItemMng_CheckGetExperience`

## src/cs4/Seimei/src/KuonMsg.c

- [ ] `KnMsgMng_SendMsg`
- [ ] `KnMsgMng_SendMsgEx`
- [ ] `KnMsgMng_SendMsgEx_SetMdlId_AnimId`

## src/cs4/Seimei/src/MathUtil.c

- [ ] `Math_GetDist`
- [ ] `Math_GotoVector`
- [ ] `Math_GotoVector2`
- [ ] `Math_GotoVectorXZ`

## src/cs4/Seimei/src/MiniGame/sgh/sghMode.c

- [ ] `__sghMode_AIThink` — `.word`
- [ ] `__sghMode_OrderPlayerEnd` — `.word`
- [ ] `sghMode_Execute` — `.word`

## src/cs4/Seimei/src/Model.c

- [ ] `SetModelTargetToModel`
- [ ] `SetModelTargetToPos`

## src/cs4/Seimei/src/My.c

- [ ] `SetHeartRate`
- [ ] `SetMyTotterMode`

## src/cs4/Seimei/src/MyDamage.c

- [ ] `SetMyDamageProc` — `.word`

## src/cs4/Seimei/src/MyThk.c

- [ ] `CheckMyCrouchState`

## src/cs4/Seimei/src/Object.c

- [ ] `CheckDoorOpen`

## src/cs4/Seimei/src/Sound/Snd.c

- [ ] `SND_RemoveSec` — `.word`
- [ ] `SND_Update`

## src/cs4/Seimei/src/Sound/SndSq.c

- [ ] `SND_SqFadeStart`

## src/cs4/Seimei/src/Sound/SndVoice.c

- [ ] `_Proc2D` — `.word`
- [ ] `_Proc3D` — `.word`

## src/cs4/Seimei/src/Title.c

- [ ] `TitleLoop`

## src/cs4/Seimei/src/menu/menu_util.c

- [ ] `GetItemData`
- [ ] `MI_CntUp_ItemScrl`
- [ ] `MI_Decide_ItemScrl`
- [ ] `MI_Evrfrm_BtnGuide`
- [ ] `MI_Evrfrm_HelpStr`
- [ ] `MI_Evrfrm_ItemScrl`
- [ ] `MI_Evrfrm_Num`
- [ ] `MI_Gene1_ItemScrl`
- [ ] `MI_Gene2_ItemScrl`
- [ ] `Menu_CheckItemOnCursor`
- [ ] `Menu_ScrlCheck_down`

## src/cs4/Seimei/src/sfx/PtclMng.c

- [ ] `_Model2_SetMdlParamToMdlMng`
- [ ] `_SetMdlParamToMdlMng`
- [ ] `_SubFunc_Plume_Move`
- [ ] `__SFX_ActAnimSprite`
- [ ] `__SFX_ActAnimSprite2`
- [ ] `__SFX_ActConnectedSprite`
- [ ] `__SFX_ActDefault`
- [ ] `__SFX_ActModel2`
- [ ] `__SFX_ActPlume`
- [ ] `__SFX_ActSprite`
- [ ] `__SFX_ActSprite2`
- [ ] `__SFX_ActTracer`
- [ ] `__SFX_DrawPtclConnectedSprite`
- [ ] `__SFX_DrawPtclSprite`
- [ ] `__SFX_DrawPtclSprite2`
- [ ] `__SFX_InitAnimSprite`
- [ ] `__SFX_InitAnimSprite2`
- [ ] `__SFX_InitConnectedSprite`
- [ ] `__SFX_InitDefault`
- [ ] `__SFX_InitDistortion`
- [ ] `__SFX_InitModel2`
- [ ] `__SFX_InitPlume`
- [ ] `__SFX_InitSprite`
- [ ] `__SFX_InitTracer`

## src/cs4/Seimei/src/sfx/SfxCommon.c

- [ ] `SfxCalc_CheckInsightCamera` — `.word`
- [ ] `SfxCalc_DirMakeFromQtn` — `.word`
- [ ] `SfxCalc_MakeMatrixFromDir`
- [ ] `SfxCalc_MakeMatrix_SPYRT`
- [ ] `SfxCalc_Vector2Angle`

## src/cs4/Seimei/src/sfx/SfxDomanString.c

- [ ] `SfxDomanString_Draw`

## src/cs4/Seimei/src/sfx/SfxDraw.c

- [ ] `SfxDraw_DrawSprite_Wld`
- [ ] `SfxDraw_DrawSprite_Wld2`
- [ ] `SfxDraw_DrawSprite_Wld2Pt`

## src/cs4/Seimei/src/sfx/SfxFlicker.c

- [ ] `_DrawFanCircle_3D`
- [ ] `_DrawFanCircle_3D_YAxis`

## src/cs4/Seimei/src/sfx/SfxMng.c

- [ ] `_SubFunc_Plume_Move`
- [ ] `__SFXMNG_CallEmitter_Act`
- [ ] `__SFXMNG_CallSfx_Act`
- [ ] `__SFXMNG_Default2_Act`
- [ ] `__SFXMNG_Default_Act`
- [ ] `__SFXMNG_Ground_Act`
- [ ] `__SFXMNG_Ground_Init`

## src/cs4/Seimei/src/sfx/SfxTracer.c

- [ ] `_DrawCross`
- [ ] `_DrawSpriteLine`

## src/unklib_00195CA0.c

- [ ] `clearGsMem`
- [ ] `handler_endimage`
- [ ] `vblankHandler`
