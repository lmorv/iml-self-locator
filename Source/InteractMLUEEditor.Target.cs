

using UnrealBuildTool;
using System.Collections.Generic;

public class InteractMLUEEditorTarget : TargetRules
{
	public InteractMLUEEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "InteractMLUE" } );
	}
}
