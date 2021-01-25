/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * Scripts for spells with SPELLFAMILY_DEATHKNIGHT and SPELLFAMILY_GENERIC spells used by deathknight players.
 * Ordered alphabetically using scriptname.
 * Scriptnames of files in this file should be prefixed with "spell_dk_".
 */

#include "ScriptMgr.h"
#include "Containers.h"
#include "ObjectMgr.h"
#include "Player.h"
#include "SpellAuraEffects.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellScript.h"

enum DeathKnightSpells
{
    SPELL_DK_ARMY_FLESH_BEAST_TRANSFORM         = 127533,
    SPELL_DK_ARMY_GEIST_TRANSFORM               = 127534,
    SPELL_DK_ARMY_NORTHREND_SKELETON_TRANSFORM  = 127528,
    SPELL_DK_ARMY_SKELETON_TRANSFORM            = 127527,
    SPELL_DK_ARMY_SPIKED_GHOUL_TRANSFORM        = 127525,
    SPELL_DK_ARMY_SUPER_ZOMBIE_TRANSFORM        = 127526,
    SPELL_DK_BLOOD_PLAGUE                       = 55078,
    SPELL_DK_BLOOD_PRESENCE                     = 48263,
    SPELL_DK_BLOOD_SHIELD_MASTERY               = 77513,
    SPELL_DK_BLOOD_SHIELD_ABSORB                = 77535,
    SPELL_DK_CHAINS_OF_ICE                      = 45524,
    SPELL_DK_CORPSE_EXPLOSION_TRIGGERED         = 43999,
    SPELL_DK_DEATH_AND_DECAY_DAMAGE             = 52212,
    SPELL_DK_DEATH_AND_DECAY_SLOW               = 143375,
    SPELL_DK_DEATH_COIL_BARRIER                 = 115635,
    SPELL_DK_DEATH_COIL_DAMAGE                  = 47632,
    SPELL_DK_DEATH_COIL_HEAL                    = 47633,
    SPELL_DK_DEATH_GRIP                         = 49576,
    SPELL_DK_DEATH_GRIP_PULL                    = 49575,
    SPELL_DK_DEATH_GRIP_VISUAL                  = 55719,
    SPELL_DK_DEATH_GRIP_TAUNT                   = 57603,
    SPELL_DK_DEATH_STRIKE_HEAL                  = 45470,
    SPELL_DK_DECOMPOSING_AURA                   = 199720,
    SPELL_DK_DECOMPOSING_AURA_DAMAGE            = 199721,
    SPELL_DK_ENHANCED_DEATH_COIL                = 157343,
    SPELL_DK_FROST_FEVER                        = 55095,
    SPELL_DK_GHOUL_EXPLODE                      = 47496,
    SPELL_DK_GLYPH_OF_ABSORB_MAGIC              = 159415,
    SPELL_DK_GLYPH_OF_ANTI_MAGIC_SHELL          = 58623,
    SPELL_DK_GLYPH_OF_ARMY_OF_THE_DEAD          = 58669,
    SPELL_DK_GLYPH_OF_DEATH_COIL                = 63333,
    SPELL_DK_GLYPH_OF_DEATH_AND_DECAY           = 58629,
    SPELL_DK_GLYPH_OF_FOUL_MENAGERIE            = 58642,
    SPELL_DK_GLYPH_OF_REGENERATIVE_MAGIC        = 146648,
    SPELL_DK_GLYPH_OF_RUNIC_POWER_TRIGGERED     = 159430,
    SPELL_DK_GLYPH_OF_SWIFT_DEATH               = 146645,
    SPELL_DK_GLYPH_OF_THE_GEIST                 = 58640,
    SPELL_DK_GLYPH_OF_THE_SKELETON              = 146652,
    SPELL_DK_IMPROVED_BLOOD_PRESENCE            = 50371,
    SPELL_DK_IMPROVED_SOUL_REAPER               = 157342,
    SPELL_DK_RUNIC_POWER_ENERGIZE               = 49088,
    SPELL_DK_SCENT_OF_BLOOD                     = 49509,
    SPELL_DK_SCENT_OF_BLOOD_TRIGGERED           = 50421,
    SPELL_DK_SCOURGE_STRIKE_TRIGGERED           = 70890,
    SPELL_DK_SHADOW_OF_DEATH                    = 164047,
    SPELL_DK_SOUL_REAPER_DAMAGE                 = 114867,
    SPELL_DK_SOUL_REAPER_HASTE                  = 114868,
    SPELL_DK_T15_DPS_4P_BONUS                   = 138347,
    SPELL_DK_UNHOLY_PRESENCE                    = 48265,
    SPELL_DK_WILL_OF_THE_NECROPOLIS             = 206967,
    SPELL_DK_BLOOD_BOIL_TRIGGERED               = 65658,
    SPELL_DK_BLOOD_GORGED_HEAL                  = 50454,
    SPELL_DK_DEATH_STRIKE_ENABLER               = 89832,
    SPELL_DK_FROST_PRESENCE                     = 48266,
    SPELL_DK_IMPROVED_FROST_PRESENCE            = 50385,
    SPELL_DK_IMPROVED_FROST_PRESENCE_TRIGGERED  = 50385,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE           = 50392,
    SPELL_DK_IMPROVED_UNHOLY_PRESENCE_TRIGGERED = 55222,
    SPELL_DK_RUNE_TAP                           = 48982,
    SPELL_DK_CORPSE_EXPLOSION_VISUAL            = 51270,
    SPELL_DK_MASTER_OF_GHOULS                   = 52143,
    SPELL_DK_GHOUL_AS_GUARDIAN                  = 46585,
    SPELL_DK_GHOUL_AS_PET                       = 52150,
    SPELL_DK_ROILING_BLOOD                      = 108170,    
    SPELL_DK_CHILBLAINS                         = 50041,
    SPELL_DK_CHAINS_OF_ICE_ROOT                 = 53534,
    SPELL_DK_PLAGUE_LEECH                       = 123693,
    SPELL_DK_PERDITION                          = 123981,
    SPELL_DK_SHROUD_OF_PURGATORY                = 116888,
    SPELL_DK_PURGATORY_INSTAKILL                = 123982,
    SPELL_DK_BLOOD_RITES                        = 50034,
    SPELL_DK_DEATH_SIPHON_HEAL                  = 116783,
    SPELL_DK_BLOOD_CHARGE                       = 114851,
    SPELL_DK_BOOD_TAP                           = 45529,
    SPELL_DK_PILLAR_OF_FROST                    = 51271,
    SPELL_DK_CONVERSION                         = 119975,
    SPELL_DK_WEAKENED_BLOWS                     = 115798,
    SPELL_DK_SCARLET_FEVER                      = 81132,
    SPELL_DK_SCENT_OF_BLOOD_AURA                = 50421,
    SPELL_DK_DESECRATED_GROUND                  = 118009,
    SPELL_DK_DESECRATED_GROUND_IMMUNE           = 115018,
    SPELL_DK_ASPHYXIATE                         = 108194,
    SPELL_DK_DARK_INFUSION_STACKS               = 91342,
    SPELL_DK_DARK_INFUSION_AURA                 = 93426,
    SPELL_DK_RUNIC_CORRUPTION_REGEN             = 51460,
    SPELL_DK_RUNIC_EMPOWERMENT                  = 81229,
    SPELL_DK_GOREFIENDS_GRASP_GRIP_VISUAL       = 114869,
    SPELL_DK_SLUDGE_BELCHER_AURA                = 207313,
    SPELL_DK_SLUDGE_BELCHER_ABOMINATION         = 212027,
    SPELL_DK_RAISE_DEAD                         = 46584,
    SPELL_DK_RAISE_DEAD_GHOUL                   = 52150,
    SPELL_DK_GEIST_TRANSFORM                    = 121916,
    SPELL_DK_ANTI_MAGIC_BARRIER                 = 205725,
    SPELL_DK_RUNIC_CORRUPTION                   = 51462,
    SPELL_DK_NECROSIS                           = 207346,
    SPELL_DK_NECROSIS_EFFECT                    = 216974,
    SPELL_DK_ALL_WILL_SERVE                     = 194916,
    SPELL_DK_ALL_WILL_SERVE_SUMMON              = 196910,
    SPELL_DK_BREATH_OF_SINDRAGOSA               = 152279,
    SPELL_DK_DEATH_GRIP_ONLY_JUMP               = 146599,
    SPELL_DK_HEART_STRIKE                       = 206930,
    SPELL_DK_FESTERING_WOUND                    = 194310,
    SPELL_DK_FESTERING_WOUND_DAMAGE             = 194311,
    SPELL_DK_BONE_SHIELD                        = 195181,
    SPELL_DK_BLOOD_MIRROR_DAMAGE                = 221847,
    SPELL_DK_BLOOD_MIRROR                       = 206977,
    SPELL_DK_BONESTORM_HEAL                     = 196545,
    SPELL_DK_GLACIAL_ADVANCE                    = 194913,
    SPELL_DK_GLACIAL_ADVANCE_DAMAGE             = 195975,
    SPELL_DK_HOWLING_BLAST                      = 49184,
    SPELL_DK_HOWLING_BLAST_AOE                  = 237680,
    SPELL_DK_RIME_BUFF                          = 59052,
    SPELL_DK_NORTHREND_WINDS                    = 204088,
    SPELL_DK_KILLING_MACHINE                    = 51124,
    SPELL_DK_REMORSELESS_WINTER_SLOW_DOWN       = 211793,
    SPELL_DK_EPIDEMIC                           = 207317,
    SPELL_DK_EPIDEMIC_DAMAGE_SINGLE             = 212739,
    SPELL_DK_EPIDEMIC_DAMAGE_AOE                = 215969,
    SPELL_DK_VIRULENT_PLAGUE                    = 191587,
    SPELL_DK_VIRULENT_ERUPTION                  = 191685,
    SPELL_DK_OUTBREAK_PERIODIC                  = 196782,
    SPELL_DK_DEFILE                             = 152280,
    SPELL_DK_DEFILE_DAMAGE                      = 156000,
    SPELL_DK_DEFILE_DUMMY                       = 156004,
    SPELL_DK_DEFILE_MASTERY                     = 218100,
    SPELL_DK_UNHOLY_FRENZY                      = 207289,
    SPELL_DK_UNHOLY_FRENZY_BUFF                 = 207290,
    SPELL_DK_PESTILENT_PUSTULES                 = 194917,
    SPELL_DK_CASTIGATOR                         = 207305,
    SPELL_DK_UNHOLY_VIGOR                       = 196263,
    SPELL_DK_RECENTLY_USED_DEATH_STRIKE         = 180612,
    SPELL_DK_FROST                              = 137006,
    SPELL_DK_DEATH_STRIKE_OFFHAND               = 66188,
    SPELL_DK_VAMPIRIC_BLOOD                     = 55233,
    SPELL_DK_CRIMSOM_SCOURGE                    = 81136,
    SPELL_DK_CLAWING_SHADOWS                    = 207311,
    SPELL_DK_INFECTED_CLAWS                     = 207272,
    SPELL_DK_SUMMON_DEFILE 						= 169018,
    SPELL_DK_HARBINGER_OF_THE_DOOM 				= 276023,
    SPELL_DK_PESTILENCE 						= 277234,
    SPELL_DK_ANTIMAGIC_ZONE_DAMAGE_TAKEN 		= 145629,
    SPELL_DK_DARK_SIMULACRUM 					= 77606,
    SPELL_DK_DARK_SIMULACRUM_PROC 				= 77616,
    SPELL_DK_ICECAP 							= 207126,
    SPELL_DK_COLD_HEART_CHARGE 					= 281209,
    SPELL_DK_COLD_HEART_DAMAGE 					= 281210,
    SPELL_DK_OSSUARY_MOD_MAX_POWER 				= 219786,
    SPELL_DK_OSSUARY_MOD_POWER_COST 			= 219788,
    SPELL_DK_GRIP_OF_THE_DEAD 					= 273952,
    SPELL_DK_GRIP_OF_THE_DEAD_PERIODIC 			= 273980,
    SPELL_DK_GRIP_OF_THE_DEAD_SLOW 				= 273977,
    SPELL_DK_VORACIOUS 							= 273953,
    SPELL_DK_VORACIOUS_MOD_LEECH 				= 274009,
    SPELL_DK_RED_THIRST 						= 205723,
    SPELL_DK_PURGATORY 							= 114556,
    SPELL_DK_BONESTORM 							= 194844,
};

enum Misc
{
    NPC_DK_DANCING_RUNE_WEAPON                  = 27893
};

// 70656 - Advantage (T10 4P Melee Bonus)
class spell_dk_advantage_t10_4p : public SpellScriptLoader
{
public:
    spell_dk_advantage_t10_4p() : SpellScriptLoader("spell_dk_advantage_t10_4p") { }

    class spell_dk_advantage_t10_4p_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_dk_advantage_t10_4p_AuraScript);

        bool CheckProc(ProcEventInfo& eventInfo)
        {
            if (Unit* caster = eventInfo.GetActor())
            {
                Player* player = caster->ToPlayer();
                if (!player  || caster->getClass() != CLASS_DEATH_KNIGHT)
                    return false;

                for (uint8 i = 0; i < player->GetMaxPower(POWER_RUNES); ++i)
                    if (player->GetRuneCooldown(i) == 0)
                        return false;

                return true;
            }

            return false;
        }

        void Register() override
        {
            DoCheckProc += AuraCheckProcFn(spell_dk_advantage_t10_4p_AuraScript::CheckProc);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_dk_advantage_t10_4p_AuraScript();
    }
};

// 48707 - Anti-Magic Shell
class spell_dk_anti_magic_shell : public SpellScriptLoader
{
    public:
        spell_dk_anti_magic_shell() : SpellScriptLoader("spell_dk_anti_magic_shell") { }

        class spell_dk_anti_magic_shell_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_anti_magic_shell_AuraScript);

        public:
            spell_dk_anti_magic_shell_AuraScript()
            {
                absorbPct = 0;
                maxHealth = 0;
                absorbedAmount = 0;
            }

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_RUNIC_POWER_ENERGIZE, SPELL_DK_VOLATILE_SHIELDING });
            }

            bool Load() override
            {
                absorbPct = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue(GetCaster());
                maxHealth = GetCaster()->GetMaxHealth();
                absorbedAmount = 0;
                return true;
            }

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = CalculatePct(maxHealth, absorbPct);
            }

            void Trigger(AuraEffect* aurEff, DamageInfo& /*dmgInfo*/, uint32& absorbAmount)
            {
                absorbedAmount += absorbAmount;

                if (!GetTarget()->HasAura(SPELL_DK_VOLATILE_SHIELDING))
                {
                    int32 bp = 2 * absorbAmount * 100 / maxHealth;
                    GetTarget()->CastCustomSpell(SPELL_DK_RUNIC_POWER_ENERGIZE, SPELLVALUE_BASE_POINT0, bp, GetTarget(), true, nullptr, aurEff);
                }
            }

            void HandleEffectRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (AuraEffect const* volatileShielding = GetTarget()->GetAuraEffect(SPELL_DK_VOLATILE_SHIELDING, EFFECT_1))
                {
                    int32 damage = CalculatePct(absorbedAmount, volatileShielding->GetAmount());
                    GetTarget()->CastCustomSpell(SPELL_DK_VOLATILE_SHIELDING_DAMAGE, SPELLVALUE_BASE_POINT0, damage, nullptr, TRIGGERED_FULL_MASK, nullptr, volatileShielding);
                }
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_anti_magic_shell_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
                AfterEffectAbsorb += AuraEffectAbsorbFn(spell_dk_anti_magic_shell_AuraScript::Trigger, EFFECT_0);
                AfterEffectRemove += AuraEffectRemoveFn(spell_dk_anti_magic_shell_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB, AURA_EFFECT_HANDLE_REAL);
            }

        private:
            int32 absorbPct;
            int32 maxHealth;
            uint32 absorbedAmount;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_anti_magic_shell_AuraScript();
        }
};

static uint32 const ArmyTransforms[]
{
    SPELL_DK_ARMY_FLESH_BEAST_TRANSFORM,
    SPELL_DK_ARMY_GEIST_TRANSFORM,
    SPELL_DK_ARMY_NORTHREND_SKELETON_TRANSFORM,
    SPELL_DK_ARMY_SKELETON_TRANSFORM,
    SPELL_DK_ARMY_SPIKED_GHOUL_TRANSFORM,
    SPELL_DK_ARMY_SUPER_ZOMBIE_TRANSFORM
};

// 127517 - Army Transform
/// 6.x, does this belong here or in spell_generic? where do we cast this? sniffs say this is only cast when caster has glyph of foul menagerie.
class spell_dk_army_transform : public SpellScriptLoader
{
    public:
        spell_dk_army_transform() : SpellScriptLoader("spell_dk_army_transform") { }

        class spell_dk_army_transform_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_army_transform_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_GLYPH_OF_FOUL_MENAGERIE });
            }

            bool Load() override
            {
                return GetCaster()->IsGuardian();
            }

            SpellCastResult CheckCast()
            {
                if (Unit* owner = GetCaster()->GetOwner())
                    if (owner->HasAura(SPELL_DK_GLYPH_OF_FOUL_MENAGERIE))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_SPELL_UNAVAILABLE;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetCaster(), Trinity::Containers::SelectRandomContainerElement(ArmyTransforms), true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_army_transform_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_dk_army_transform_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_army_transform_SpellScript();
        }
};

// 50842 - Blood Boil
class spell_dk_blood_boil : public SpellScriptLoader
{
    public:
        spell_dk_blood_boil() : SpellScriptLoader("spell_dk_blood_boil") { }

        class spell_dk_blood_boil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_blood_boil_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_BLOOD_PLAGUE });
            }

            void HandleEffect()
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_BLOOD_PLAGUE, true);
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_dk_blood_boil_SpellScript::HandleEffect);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_blood_boil_SpellScript();
        }
};

// 49028 - Dancing Rune Weapon
/// 7.1.5
class spell_dk_dancing_rune_weapon : public SpellScriptLoader
{
    public:
        spell_dk_dancing_rune_weapon() : SpellScriptLoader("spell_dk_dancing_rune_weapon") { }

        class spell_dk_dancing_rune_weapon_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_dancing_rune_weapon_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                if (!sObjectMgr->GetCreatureTemplate(NPC_DK_DANCING_RUNE_WEAPON))
                    return false;
                return true;
            }

            // This is a port of the old switch hack in Unit.cpp, it's not correct
            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                Unit* caster = GetCaster();
                if (!caster)
                    return;

                Unit* drw = nullptr;
                for (Unit* controlled : caster->m_Controlled)
                {
                    if (controlled->GetEntry() == NPC_DK_DANCING_RUNE_WEAPON)
                    {
                        drw = controlled;
                        break;
                    }
                }

                if (!drw || !drw->GetVictim())
                    return;

                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return;

                DamageInfo* damageInfo = eventInfo.GetDamageInfo();
                if (!damageInfo || !damageInfo->GetDamage())
                    return;

                int32 amount = static_cast<int32>(damageInfo->GetDamage()) / 2;
                SpellNonMeleeDamage log(drw, drw->GetVictim(), spellInfo, { spellInfo->GetSpellXSpellVisualId(drw), 0 }, spellInfo->GetSchoolMask());
                log.damage = amount;
                drw->DealDamage(drw->GetVictim(), amount, nullptr, SPELL_DIRECT_DAMAGE, spellInfo->GetSchoolMask(), spellInfo, true);
                drw->SendSpellNonMeleeDamageLog(&log);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_dancing_rune_weapon_AuraScript::HandleProc, EFFECT_1, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_dancing_rune_weapon_AuraScript();
        }
};

// 43265 - Death and Decay
class spell_dk_death_and_decay : public SpellScriptLoader
{
    public:
        spell_dk_death_and_decay() : SpellScriptLoader("spell_dk_death_and_decay") { }

        class spell_dk_death_and_decay_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_and_decay_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_TIGHTENING_GRASP, SPELL_DK_TIGHTENING_GRASP_SLOW });
            }

            void HandleDummy()
            {
                if (GetCaster()->HasAura(SPELL_DK_TIGHTENING_GRASP))
                    if (WorldLocation const* pos = GetExplTargetDest())
                        GetCaster()->CastSpell(pos->GetPositionX(), pos->GetPositionY(), pos->GetPositionZ(), SPELL_DK_TIGHTENING_GRASP_SLOW, true);
            }

            void Register() override
            {
                OnCast += SpellCastFn(spell_dk_death_and_decay_SpellScript::HandleDummy);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_and_decay_SpellScript();
        }

        class spell_dk_death_and_decay_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_death_and_decay_AuraScript);

            void HandleDummyTick(AuraEffect const* aurEff)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetTarget(), SPELL_DK_DEATH_AND_DECAY_DAMAGE, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_dk_death_and_decay_AuraScript::HandleDummyTick, EFFECT_2, SPELL_AURA_PERIODIC_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_death_and_decay_AuraScript();
        }
};

// 47541 - Death Coil
class spell_dk_death_coil : public SpellScriptLoader
{
    public:
        spell_dk_death_coil() : SpellScriptLoader("spell_dk_death_coil") { }

        class spell_dk_death_coil_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_coil_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_DEATH_COIL_DAMAGE, SPELL_DK_UNHOLY, SPELL_DK_UNHOLY_VIGOR });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                caster->CastSpell(GetHitUnit(), SPELL_DK_DEATH_COIL_DAMAGE, true);
                if (AuraEffect const* unholyAura = caster->GetAuraEffect(SPELL_DK_UNHOLY, EFFECT_6)) // can be any effect, just here to send SPELL_FAILED_DONT_REPORT on failure
                    caster->CastSpell(caster, SPELL_DK_UNHOLY_VIGOR, true, nullptr, unholyAura);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_coil_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_coil_SpellScript();
        }
};

// 52751 - Death Gate
class spell_dk_death_gate : public SpellScriptLoader
{
    public:
        spell_dk_death_gate() : SpellScriptLoader("spell_dk_death_gate") { }

        class spell_dk_death_gate_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_gate_SpellScript);

            SpellCastResult CheckClass()
            {
                if (GetCaster()->getClass() != CLASS_DEATH_KNIGHT)
                {
                    SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_MUST_BE_DEATH_KNIGHT);
                    return SPELL_FAILED_CUSTOM_ERROR;
                }

                return SPELL_CAST_OK;
            }

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, GetEffectValue(), false);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_gate_SpellScript::CheckClass);
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_gate_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_gate_SpellScript();
        }
};

// 49576 - Death Grip Initial
class spell_dk_death_grip_initial : public SpellScriptLoader
{
    public:
        spell_dk_death_grip_initial() : SpellScriptLoader("spell_dk_death_grip_initial") { }

        class spell_dk_death_grip_initial_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_grip_initial_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_DK_DEATH_GRIP_DUMMY,
                    SPELL_DK_DEATH_GRIP_JUMP,
                    SPELL_DK_BLOOD,
                    SPELL_DK_DEATH_GRIP_TAUNT
                });
            }

            SpellCastResult CheckCast()
            {
                Unit* caster = GetCaster();
                // Death Grip should not be castable while jumping/falling
                if (caster->HasUnitState(UNIT_STATE_JUMPING) || caster->HasUnitMovementFlag(MOVEMENTFLAG_FALLING))
                    return SPELL_FAILED_MOVING;

                return SPELL_CAST_OK;
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP_DUMMY, true);
                GetHitUnit()->CastSpell(GetCaster(), SPELL_DK_DEATH_GRIP_JUMP, true);
                if (GetCaster()->HasAura(SPELL_DK_BLOOD))
                    GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_DEATH_GRIP_TAUNT, true);
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_death_grip_initial_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_grip_initial_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_grip_initial_SpellScript();
        }
};

// 48743 - Death Pact
class spell_dk_death_pact : public SpellScriptLoader
{
    public:
        spell_dk_death_pact() : SpellScriptLoader("spell_dk_death_pact") { }

        class spell_dk_death_pact_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_death_pact_AuraScript);

            void HandleCalcAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                if (Unit* caster = GetCaster())
                    amount = int32(caster->CountPctFromMaxHealth(amount));
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_death_pact_AuraScript::HandleCalcAmount, EFFECT_1, SPELL_AURA_SCHOOL_HEAL_ABSORB);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_death_pact_AuraScript();
        }
};

// 49998 - Death Strike
class spell_dk_death_strike : public SpellScriptLoader
{
    public:
        spell_dk_death_strike() : SpellScriptLoader("spell_dk_death_strike") { }

        class spell_dk_death_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_death_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_DK_DEATH_STRIKE_HEAL,
                    SPELL_DK_BLOOD_SHIELD_MASTERY,
                    SPELL_DK_BLOOD_SHIELD_ABSORB,
                    SPELL_DK_RECENTLY_USED_DEATH_STRIKE,
                    SPELL_DK_FROST,
                    SPELL_DK_DEATH_STRIKE_OFFHAND
                });
            }

            void HandleHeal(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                //TODO: heal = std::min(10% health, 20% of all damage taken in last 5 seconds)
                int32 heal = CalculatePct(caster->GetMaxHealth(), GetSpellInfo()->GetEffect(EFFECT_4)->CalcValue());
                caster->CastCustomSpell(SPELL_DK_DEATH_STRIKE_HEAL, SPELLVALUE_BASE_POINT0, heal, caster, true);

                if (AuraEffect const* aurEff = caster->GetAuraEffect(SPELL_DK_BLOOD_SHIELD_MASTERY, EFFECT_0))
                    caster->CastCustomSpell(SPELL_DK_BLOOD_SHIELD_ABSORB, SPELLVALUE_BASE_POINT0, CalculatePct(heal, aurEff->GetAmount()), caster);

                if (caster->HasAura(SPELL_DK_FROST))
                    caster->CastSpell(GetHitUnit(), SPELL_DK_DEATH_STRIKE_OFFHAND, true);
            }

            void TriggerRecentlyUsedDeathStrike()
            {
                GetCaster()->CastSpell(GetCaster(), SPELL_DK_RECENTLY_USED_DEATH_STRIKE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_death_strike_SpellScript::HandleHeal, EFFECT_1, SPELL_EFFECT_WEAPON_PERCENT_DAMAGE);
                AfterCast += SpellCastFn(spell_dk_death_strike_SpellScript::TriggerRecentlyUsedDeathStrike);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_death_strike_SpellScript();
        }
};

// 85948 - Festering Strike
class spell_dk_festering_strike : public SpellScriptLoader
{
    public:
        spell_dk_festering_strike() : SpellScriptLoader("spell_dk_festering_strike") { }

        class spell_dk_festering_strike_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_festering_strike_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_FESTERING_WOUND });
            }

            void HandleScriptEffect(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastCustomSpell(SPELL_DK_FESTERING_WOUND, SPELLVALUE_AURA_STACK, GetEffectValue(), GetHitUnit(), TRIGGERED_FULL_MASK);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_festering_strike_SpellScript::HandleScriptEffect, EFFECT_2, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_festering_strike_SpellScript();
        }
};

// 47496 - Explode, Ghoul spell for Corpse Explosion
class spell_dk_ghoul_explode : public SpellScriptLoader
{
    public:
        spell_dk_ghoul_explode() : SpellScriptLoader("spell_dk_ghoul_explode") { }

        class spell_dk_ghoul_explode_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_ghoul_explode_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_CORPSE_EXPLOSION_TRIGGERED });
            }

            void HandleDamage(SpellEffIndex /*effIndex*/)
            {
                SetHitDamage(GetCaster()->CountPctFromMaxHealth(GetEffectInfo(EFFECT_2)->CalcValue(GetCaster())));
            }

            void Suicide(SpellEffIndex /*effIndex*/)
            {
                if (Unit* unitTarget = GetHitUnit())
                {
                    // Corpse Explosion (Suicide)
                    unitTarget->CastSpell(unitTarget, SPELL_DK_CORPSE_EXPLOSION_TRIGGERED, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode_SpellScript::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
                OnEffectHitTarget += SpellEffectFn(spell_dk_ghoul_explode_SpellScript::Suicide, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_ghoul_explode_SpellScript();
        }
};

// 206940 - Mark of Blood
class spell_dk_mark_of_blood : public SpellScriptLoader
{
    public:
        spell_dk_mark_of_blood() : SpellScriptLoader("spell_dk_mark_of_blood") { }

        class spell_dk_mark_of_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_mark_of_blood_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_MARK_OF_BLOOD_HEAL });
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                if (Unit* caster = GetCaster())
                    caster->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_MARK_OF_BLOOD_HEAL, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_mark_of_blood_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_mark_of_blood_AuraScript();
        }
};

// 207346 - Necrosis
class spell_dk_necrosis : public SpellScriptLoader
{
    public:
        spell_dk_necrosis() : SpellScriptLoader("spell_dk_necrosis") { }

        class spell_dk_necrosis_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_necrosis_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_NECROSIS_EFFECT });
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                GetTarget()->CastSpell(eventInfo.GetProcTarget(), SPELL_DK_NECROSIS_EFFECT, true);
            }

            void Register() override
            {
                OnEffectProc += AuraEffectProcFn(spell_dk_necrosis_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_necrosis_AuraScript();
        }
};

// 121916 - Glyph of the Geist (Unholy)
/// 6.x, does this belong here or in spell_generic? apply this in creature_template_addon? sniffs say this is always cast on raise dead.
class spell_dk_pet_geist_transform : public SpellScriptLoader
{
    public:
        spell_dk_pet_geist_transform() : SpellScriptLoader("spell_dk_pet_geist_transform") { }

        class spell_dk_pet_geist_transform_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_pet_geist_transform_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_GLYPH_OF_THE_GEIST });
            }

            bool Load() override
            {
                return GetCaster()->IsPet();
            }

            SpellCastResult CheckCast()
            {
                if (Unit* owner = GetCaster()->GetOwner())
                    if (owner->HasAura(SPELL_DK_GLYPH_OF_THE_GEIST))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_SPELL_UNAVAILABLE;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_pet_geist_transform_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_pet_geist_transform_SpellScript();
        }
};

// 147157 Glyph of the Skeleton (Unholy)
/// 6.x, does this belong here or in spell_generic? apply this in creature_template_addon? sniffs say this is always cast on raise dead.
class spell_dk_pet_skeleton_transform : public SpellScriptLoader
{
    public:
        spell_dk_pet_skeleton_transform() : SpellScriptLoader("spell_dk_pet_skeleton_transform") { }

        class spell_dk_pet_skeleton_transform_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_pet_skeleton_transform_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_GLYPH_OF_THE_SKELETON });
            }

            SpellCastResult CheckCast()
            {
                if (Unit* owner = GetCaster()->GetOwner())
                    if (owner->HasAura(SPELL_DK_GLYPH_OF_THE_SKELETON))
                        return SPELL_CAST_OK;

                return SPELL_FAILED_SPELL_UNAVAILABLE;
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_dk_pet_skeleton_transform_SpellScript::CheckCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_pet_skeleton_transform_SpellScript();
        }
};

// 61257 - Runic Power Back on Snare/Root
/// 7.1.5
class spell_dk_pvp_4p_bonus : public SpellScriptLoader
{
    public:
        spell_dk_pvp_4p_bonus() : SpellScriptLoader("spell_dk_pvp_4p_bonus") { }

        class spell_dk_pvp_4p_bonus_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_pvp_4p_bonus_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_RUNIC_RETURN });
            }

            bool CheckProc(ProcEventInfo& eventInfo)
            {
                SpellInfo const* spellInfo = eventInfo.GetSpellInfo();
                if (!spellInfo)
                    return false;

                return (spellInfo->GetAllEffectsMechanicMask() & ((1 << MECHANIC_ROOT) | (1 << MECHANIC_SNARE))) != 0;
            }

            void HandleProc(AuraEffect const* /*aurEff*/, ProcEventInfo& eventInfo)
            {
                PreventDefaultAction();
                eventInfo.GetActionTarget()->CastSpell(nullptr, SPELL_DK_RUNIC_RETURN, true);
            }

            void Register() override
            {
                DoCheckProc += AuraCheckProcFn(spell_dk_pvp_4p_bonus_AuraScript::CheckProc);
                OnEffectProc += AuraEffectProcFn(spell_dk_pvp_4p_bonus_AuraScript::HandleProc, EFFECT_0, SPELL_AURA_DUMMY);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_pvp_4p_bonus_AuraScript();
        }
};

// 46584 - Raise Dead
class spell_dk_raise_dead : public SpellScriptLoader
{
    public:
        spell_dk_raise_dead() : SpellScriptLoader("spell_dk_raise_dead") { }

        class spell_dk_raise_dead_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_raise_dead_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_RAISE_DEAD_SUMMON, SPELL_DK_SLUDGE_BELCHER, SPELL_DK_SLUDGE_BELCHER_SUMMON });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                uint32 spellId = SPELL_DK_RAISE_DEAD_SUMMON;
                if (GetCaster()->HasAura(SPELL_DK_SLUDGE_BELCHER))
                    spellId = SPELL_DK_SLUDGE_BELCHER_SUMMON;

                GetCaster()->CastSpell(nullptr, spellId, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_raise_dead_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_raise_dead_SpellScript();
        }
};

// 115994 - Unholy Blight
class spell_dk_unholy_blight : public SpellScriptLoader
{
    public:
        spell_dk_unholy_blight() : SpellScriptLoader("spell_dk_unholy_blight") { }

        class spell_dk_unholy_blight_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_dk_unholy_blight_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DK_FROST_FEVER, SPELL_DK_BLOOD_PLAGUE });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_FROST_FEVER, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_DK_BLOOD_PLAGUE, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_dk_unholy_blight_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_dk_unholy_blight_SpellScript();
        }
};

// 55233 - Vampiric Blood
class spell_dk_vampiric_blood : public SpellScriptLoader
{
    public:
        spell_dk_vampiric_blood() : SpellScriptLoader("spell_dk_vampiric_blood") { }

        class spell_dk_vampiric_blood_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_dk_vampiric_blood_AuraScript);

            void CalculateAmount(AuraEffect const* /*aurEff*/, int32& amount, bool& /*canBeRecalculated*/)
            {
                amount = GetUnitOwner()->CountPctFromMaxHealth(amount);
            }

            void Register() override
            {
                DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_dk_vampiric_blood_AuraScript::CalculateAmount, EFFECT_1, SPELL_AURA_MOD_INCREASE_HEALTH_2);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_dk_vampiric_blood_AuraScript();
        }
};

void AddSC_deathknight_spell_scripts()
{
    new spell_dk_advantage_t10_4p();
    new spell_dk_anti_magic_shell();
    new spell_dk_army_transform();
    new spell_dk_blood_boil();
    new spell_dk_dancing_rune_weapon();
    new spell_dk_death_and_decay();
    new spell_dk_death_coil();
    new spell_dk_death_gate();
    new spell_dk_death_grip_initial();
    new spell_dk_death_pact();
    new spell_dk_death_strike();
    new spell_dk_festering_strike();
    new spell_dk_ghoul_explode();
    new spell_dk_mark_of_blood();
    new spell_dk_necrosis();
    new spell_dk_pet_geist_transform();
    new spell_dk_pet_skeleton_transform();
    new spell_dk_pvp_4p_bonus();
    new spell_dk_raise_dead();
    new spell_dk_unholy_blight();
    new spell_dk_vampiric_blood();
}
