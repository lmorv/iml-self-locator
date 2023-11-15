

using UnrealBuildTool;
using System.Collections.Generic;

public class InteractMLUETarget : TargetRules
{
	public InteractMLUETarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;

		ExtraModuleNames.AddRange( new string[] { "InteractMLUE" } );
	}
}
